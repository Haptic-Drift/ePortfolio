const express = require('express');
const router = express.Router();
const ctrlTrips = require('../controllers/trips');
const authController = require('../controllers/authentication');
const auth = require('./auth');
const authorizeRole = require('../authorization');

router
  .route('/trips')
  .get(ctrlTrips.tripsList)
  .post(auth, authorizeRole('admin'), ctrlTrips.tripsAddTrip);

router
  .route('/trips/:tripCode')
  .get(ctrlTrips.tripsFindByCode)
  .put(auth, authorizeRole('admin'), ctrlTrips.tripsUpdateTrip);

router
  .route('/register')
  .post(authController.register);

router
  .route('/login')
  .post(authController.login);

module.exports = router;