# Original Travlr Getaways Artifact

This directory contains the original Travlr Getaways application developed in CS 465: Full Stack Development I. This version represents the application before the CS 499 software engineering and design enhancement was implemented.

## Source Code

- [Angular Administrative Application](app_admin/)
- [REST API](app_api/)
- [Server Application](app_server/)
- [Application Entry Point](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/app.js)
- [Package Configuration](https://github.com/Haptic-Drift/ePortfolio/blob/main/software-engineering/original/package.json)

## About This Version

The original application uses the MEAN stack and includes a public customer-facing website, an Angular administrative single-page application, an Express and Node.js REST API, and MongoDB for data persistence.

The application includes JSON Web Token (JWT) authentication. However, the original implementation does not distinguish between standard users and administrators when determining access to protected trip-management functionality. This authorization limitation became the focus of the CS 499 software engineering and design enhancement.

[Return to Enhancement One](../)
