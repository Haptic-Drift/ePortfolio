const mongoose = require('mongoose');
const Trip = mongoose.model('trips');

const tripsList = async (req, res) => {
  try {
    const trips = await Trip.find({});
    return res
      .status(200)
      .json(trips);
  } catch (err) {
    return res
      .status(404)
      .json(err);
  }
};

const tripsFindByCode = async (req, res) => {
  try {
    const trip = await Trip.findOne({ code: req.params.tripCode });

    if (!trip) {
      return res
        .status(404)
        .json({ "message": "tripCode not found" });
    }

    return res
      .status(200)
      .json(trip);
  } catch (err) {
    return res
      .status(404)
      .json(err);
  }
};

const tripsAddTrip = async (req, res) => {
  try {
    const trip = await Trip.create({
      code: req.body.code,
      name: req.body.name,
      length: req.body.length,
      start: req.body.start,
      resort: req.body.resort,
      perPerson: req.body.perPerson,
      image: req.body.image,
      description: req.body.description
    });

    return res
      .status(201)
      .json(trip);
  } catch (err) {
    return res
      .status(400)
      .json(err);
  }
};

const tripsUpdateTrip = async (req, res) => {
  try {
    const trip = await Trip.findOne({ code: req.params.tripCode });

    if (!trip) {
      return res
        .status(404)
        .json({ "message": "tripCode not found" });
    }

    trip.code = req.body.code;
    trip.name = req.body.name;
    trip.length = req.body.length;
    trip.start = req.body.start;
    trip.resort = req.body.resort;
    trip.perPerson = req.body.perPerson;
    trip.image = req.body.image;
    trip.description = req.body.description;

    await trip.save();

    return res
      .status(200)
      .json(trip);
  } catch (err) {
    return res
      .status(400)
      .json(err);
  }
};

module.exports = {
  tripsList,
  tripsFindByCode,
  tripsAddTrip,
  tripsUpdateTrip
};