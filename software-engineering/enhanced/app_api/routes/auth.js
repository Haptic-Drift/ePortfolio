const { expressjwt: jwt } = require('express-jwt');

const auth = jwt({
  secret: process.env.JWT_SECRET,
  requestProperty: 'payload',
  algorithms: ['HS256']
});

module.exports = auth;