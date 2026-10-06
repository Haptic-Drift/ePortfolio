# Original Travlr Getaways REST API

This directory contains the REST API source code for the original Travlr Getaways application developed in CS 465: Full Stack Development I.

## API Source Code

### Configuration
- [Passport Authentication Configuration](config/passport.js)

### Controllers
- [Authentication Controller](controllers/authentication.js)
- [Trip Controller](controllers/trips.js)

### Models
- [Database Configuration](models/db.js)
- [Database Seed](models/seed.js)
- [Travlr Model](models/travlr.js)
- [User Model](models/user.js)

### Routes
- [Authentication Routes](routes/auth.js)
- [API Routes](routes/index.js)

## About This Version

The original REST API provides authentication and trip-management functionality for the Travlr Getaways application. Although authenticated users can access protected functionality, this version does not distinguish between standard users and administrators when determining authorization.

This limitation became the focus of the CS 499 software engineering and design enhancement.

---

[Return to Original Travlr Getaways Artifact](../) | [Return to ePortfolio Home](../../../)
