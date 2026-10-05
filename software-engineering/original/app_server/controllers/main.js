// Controller for the home page
const homelist = (req, res) => {
  res.render('index', { title: 'Travlr Getaways' });
};

module.exports = {
  homelist
};