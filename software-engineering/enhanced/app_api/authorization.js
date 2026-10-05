const authorizeRole = (requiredRole) => {
    return (req, res, next) => {
        if (!req.payload) {
            return res.status(401).json({
                message: 'Authentication required'
            });
        }

        if (req.payload.role !== requiredRole) {
            return res.status(403).json({
                message: 'Insufficient permissions'
            });
        }

        next();
    };
};

module.exports = authorizeRole;