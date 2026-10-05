const fetch = require('node-fetch');

const travel = async (req, res) => {
  const path = '/api/trips';
  const requestOptions = {
    method: 'GET',
    redirect: 'follow'
  };

  try {
    const response = await fetch(`http://localhost:3000${path}`, requestOptions);
    const trips = await response.json();

    if (!response.ok) {
      return res.render('error', { message: 'API request failed', error: {} });
    }

    res.render('travel', {
      title: 'Travlr Getaways',
      trips
    });
  } catch (err) {
    res.render('error', { message: 'Unable to connect to API', error: err });
  }
};

module.exports = {
  travel
};