from pymongo import MongoClient
from bson.objectid import ObjectId

class AnimalShelter:
    """
    CRUD operations for Animal collection in MongoDB
    """

    def __init__(self, username='YOUR_USERNAME', password='YOUR_PASSWORD', host='YOUR_MONGODB_HOST', port=30686, db='AAC', col='animals'):
        """
        Initialize the connection to MongoDB
        """
        try:
            self.client = MongoClient(f"mongodb://{username}:{password}@{host}:{port}")
            self.database = self.client[db]
            self.collection = self.database[col]
            print("MongoDB connection successful.")
        except Exception as e:
            print("Failed to connect to MongoDB:", e)

    def create(self, data):
        """
        Insert a document into the collection.
        Returns True if successful, returns False otherwise.
        """
        if data is not None and isinstance(data, dict):
            try:
                result = self.collection.insert_one(data)
                return True if result.acknowledged else False
            except Exception as e:
                print("Insert failed:", e)
                return False
        else:
            raise ValueError("Invalid data format. Must be a non-empty dictionary.")

    def read(self, query):
        """
        Query documents in the collection based on input query.
        Returns a list of documents if successful, or empty list.
        """
        if query is not None and isinstance(query, dict):
            try:
                result = list(self.collection.find(query))
                return result
            except Exception as e:
                print("Read failed:", e)
                return []
        else:
            raise ValueError("Invalid query format. Must be a dictionary.")

    def update(self, query, new_data):
        if query and new_data:
            result = self.database.animals.update_many(query, new_data)
            return result.modified_count
        else:
            return 0

    def delete(self, query):
        if query:
            result = self.database.animals.delete_many(query)
            return result.deleted_count
        else:
            return 0
