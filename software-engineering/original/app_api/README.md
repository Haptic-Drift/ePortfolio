# Original Travlr Getaways REST API

This directory contains the REST API source code for the original Travlr Getaways application developed in CS 465: Full Stack Development I.

## API Source Code

### Configuration
- [Passport Authentication Configuration](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app_api/config/passport.js)

### Controllers
- [Authentication Controller](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app_api/controllers/authentication.js)
- [Trip Controller](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app_api/controllers/trips.js)

### Models
- [Database Configuration](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app_api/models/db.js)
- [Database Seed](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app_api/models/seed.js)
- [Travlr Model](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app_api/models/travlr.js)
- [User Model](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app_api/models/user.js)

### Routes
- [Authentication Routes](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app_api/routes/auth.js)
- [API Routes](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app_api/routes/index.js)

## About This Version

The original REST API provides authentication and trip-management functionality for the Travlr Getaways application. Although authenticated users can access protected functionality, this version does not distinguish between standard users and administrators when determining authorization.

This limitation became the focus of the CS 499 software engineering and design enhancement.

---

[Return to Original Travlr Getaways Artifact](../) | [Return to ePortfolio Home](../../../)
