# Enhanced Travlr Getaways Artifact

This directory contains the enhanced Travlr Getaways application completed for the CS 499 software engineering and design category. This version builds on the original CS 465 application by implementing role-based access control (RBAC).

## Source Code

- [Angular Administrative Application](app_admin/)
- [REST API](app_api/)
- [Server Application](app_server/)
- [Application Entry Point](app.js)
- [Package Configuration](package.json)

## About This Version

The enhanced application expands the original authentication model by distinguishing between standard users and administrators. User role information is incorporated into the authorization process so that administrative trip-management functionality is restricted based on the user's permissions.

The enhancement required coordinated changes across multiple layers of the application, including the Mongoose user model, JWT authentication, API authorization middleware, Angular authentication services, route protection, and user-interface controls.

These changes improve the application's security and demonstrate a clearer separation between authentication, which verifies who a user is, and authorization, which determines what that user is permitted to do.

[Return to Enhancement One](../)
