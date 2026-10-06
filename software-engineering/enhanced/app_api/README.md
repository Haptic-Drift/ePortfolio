# Enhanced Travlr Getaways REST API

This directory contains the REST API source code for the enhanced Travlr Getaways application completed for the CS 499 software engineering and design category. This version extends the original application with role-based access control (RBAC).

## RBAC Enhancement

- [Authorization Middleware](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/authorization.js)
- [Enhanced User Model](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/models/user.js)
- [Authentication Routes](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/routes/auth.js)
- [API Routes](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/routes/index.js)

The authorization middleware verifies administrative permissions before allowing access to protected trip-management operations. The enhanced user model supports user roles, allowing the application to distinguish between standard users and administrators.

## API Source Code

### Configuration
- [Passport Authentication Configuration](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/config/passport.js)

### Controllers
- [Authentication Controller](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/controllers/authentication.js)
- [Trip Controller](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/controllers/trips.js)

### Models
- [Database Configuration](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/models/db.js)
- [Database Seed](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/models/seed.js)
- [Travlr Model](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/models/travlr.js)
- [User Model](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/models/user.js)

### Routes
- [Authentication Routes](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/routes/auth.js)
- [API Routes](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/enhanced/app_api/routes/index.js)

## About This Version

The enhanced REST API builds on the original JWT authentication system by adding authorization based on user roles. Authentication establishes the identity of the user, while the RBAC enhancement determines whether that user has permission to perform protected administrative operations.

This enhancement creates a clearer security boundary between standard authenticated users and administrators and demonstrates the integration of authorization across the application's data model, authentication process, middleware, and API routes.

---

[Return to Enhanced Travlr Getaways Artifact](../) | [Return to ePortfolio Home](../../../)
