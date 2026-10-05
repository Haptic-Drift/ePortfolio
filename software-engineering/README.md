\# Enhancement One: Software Engineering and Design



\## Travlr Getaways



The artifact selected for the software engineering and design category is Travlr Getaways, a full-stack web application originally developed in CS 465: Full Stack Development I. The application was built using the MEAN stack and includes a public customer-facing website, an Angular administrative single-page application, an Express and Node.js REST API, and MongoDB data storage through Mongoose.



The original application included JSON Web Token (JWT) authentication that allowed authenticated users to access protected administrative functionality. However, authentication alone did not distinguish between different types of users. Any authenticated account could access the same protected trip-management operations.



\## Enhancement



For this enhancement, I expanded the original authentication model by implementing role-based access control (RBAC).



The user model was updated to include user and administrator roles, and role information was added to the JWT payload. On the API side, authorization middleware was added to verify that an authenticated user has administrator permissions before allowing protected write operations.



The Angular administrative application was also updated so that authorization is reflected in the user interface. Route protection prevents non-administrators from directly accessing protected add-trip and edit-trip pages, while administrative controls such as Add a New Trip and Edit Trip are displayed only to administrators.



Together, these changes create a clearer separation between authentication, which determines whether a user is logged in, and authorization, which determines what that user is permitted to do.



\## Original and Enhanced Artifacts



\[View the Original Travlr Getaways Source Code](original/)



\[View the Enhanced Travlr Getaways Source Code](enhanced/)



\## Skills Demonstrated



This enhancement demonstrates my ability to evaluate an existing software architecture and implement improvements across multiple layers of a full-stack application. The work required changes to the Mongoose data model, JWT authentication data, Express middleware and API routes, Angular authentication services, route guards, and user-interface templates.



The enhancement also demonstrates secure software design by enforcing authorization at the API level rather than relying only on client-side restrictions. The user interface reflects those permissions, but the API remains the primary security boundary.



\## Testing and Validation



I tested the enhancement using accounts with both user and administrator roles. A user-role account received an HTTP 403 Forbidden response when attempting a protected write operation. After the account was promoted to administrator and a new JWT was generated, the request passed the authorization middleware and reached the appropriate trip controller.



The Angular application was also tested to verify that a normal user could view trip information but could not see the Add a New Trip or Edit Trip controls or directly access their protected routes. After logging in with administrator permissions, those controls became available and the protected pages opened normally.



\## Reflection



This enhancement reinforced the difference between authentication and authorization and demonstrated how one architectural change can affect multiple layers of an application. Implementing RBAC required the database model, JWT, API middleware, Angular authentication service, route guards, and templates to work together around the same authorization decision.



The enhancement improved the original artifact by replacing a single-level login check with a more complete permissions model. It also reflects how my approach to software development has developed throughout the computer science program. I now look beyond whether a feature simply works and consider how architecture, permissions, security boundaries, maintainability, and testing affect the design as a whole.



\[Return to the ePortfolio Home Page](../)

