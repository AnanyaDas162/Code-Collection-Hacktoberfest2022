from enum import unique
from flask import Flask, render_template
from numpy import unicode_

from flask_sqlalchemy import SQLAlchemy

#....................................
from werkzeug.utils import secure_filename
import os



app = Flask(__name__)

UPLOAD_FOLDER = "D:/files/OPen badge/APP/ourapp/static/uploads"
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///users.db"
app.config['SECRET_KEY'] = "d6aac39da3ae28912e1f10b0"
app.config["UPLOAD_FOLDER"] = UPLOAD_FOLDER



db = SQLAlchemy(app)

from ourapp import route


