from enum import unique
from traitlets import default
from ourapp import db

#User database
class User(db.Model):
    id = db.Column(db.Integer(), primary_key=True,autoincrement=True) # this is the primary  key
    username= db.Column(db.String(length=30),nullable=False,unique=True)
    email_address = db.Column(db.String(length=50),nullable=False, unique=True)
    filename = db.Column(db.String(length=50),nullable=False, unique=False)
    
    def __repr__(self):
        return f'Item {self.name}' 