const express = require('express');
const router = express.Router();
const ctrlTrips = require('../controllers/trips');
const authController = require('../controllers/authentication');
const auth = require('./auth');

router
  .route('/trips')
  .get(ctrlTrips.tripsList)
  .post(auth, ctrlTrips.tripsAddTrip);

router
  .route('/trips/:tripCode')
  .get(ctrlTrips.tripsFindByCode)
  .put(auth, ctrlTrips.tripsUpdateTrip);

router
  .route('/register')
  .post(authController.register);

router
  .route('/login')
  .post(authController.login);

module.exports = router;