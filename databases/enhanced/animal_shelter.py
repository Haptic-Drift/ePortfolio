from pymongo import MongoClient
from bson.objectid import ObjectId
from dotenv import load_dotenv
import os

load_dotenv()

class AnimalShelter:
    """
    CRUD operations for Animal collection in MongoDB
    """
    def __init__(self):
        """
        Initialize the MongoDB connection using environment configuration.
        Supports both authenticated and local unauthenticated connections.
        """
        username = os.getenv("MONGO_USERNAME")
        password = os.getenv("MONGO_PASSWORD")
        host = os.getenv("MONGO_HOST")
        port = os.getenv("MONGO_PORT")
        db = os.getenv("MONGO_DB")
        col = os.getenv("MONGO_COLLECTION")

        if not all([host, port, db, col]):
            raise ValueError("Missing required MongoDB configuration.")

        port = int(port)

        try:
            if username and password:
                connection_string = (
                    f"mongodb://{username}:{password}@{host}:{port}"
                )
            else:
                connection_string = f"mongodb://{host}:{port}"

            self.client = MongoClient(connection_string)
            self.database = self.client[db]
            self.collection = self.database[col]

            print("MongoDB connection configured.")

        except Exception as e:
            print("Failed to configure MongoDB:", e)
            raise

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
        """
        Update documents in the collection based on input query.
        Returns the number of modified documents.
        """
        if not isinstance(query, dict) or not query:
            raise ValueError("Invalid query format. Must be a non-empty dictionary.")

        if not isinstance(new_data, dict) or not new_data:
            raise ValueError("Invalid update data. Must be a non-empty dictionary.")

        try:
            result = self.collection.update_many(query, new_data)
            return result.modified_count
        except Exception as e:
            print("Update failed:", e)
            return 0

    def delete(self, query):
        """
        Delete documents from the collection based on input query.
        Returns the number of deleted documents
        """
        if not isinstance(query, dict) or not query:
            raise ValueError("Invalid query format. Must be a non-empty dictionary.")

        try:
            result = self.collection.delete_many(query)
            return result.deleted_count
        except Exception as e:
            print("Delete failed:", e)
            return 0