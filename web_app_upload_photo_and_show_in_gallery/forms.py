import email
from flask_wtf import FlaskForm
from jsonschema import ValidationError
from numpy import equal
from wtforms import StringField, PasswordField , SubmitField
from wtforms.validators import Length, EqualTo, Email, DataRequired
from flask_wtf.file import FileField, FileRequired, FileAllowed
from ourapp.models import User

class Userform(FlaskForm):
    def validate_username(self, username_to_check):
        user = User.query.filter_by(username=username_to_check.data).first()
        if user:
            raise ValidationError("Username already exists")
    
    def validate_email(self, email_to_check):
        email = User.query.filter_by(email_address=email_to_check.data).first()
        if email:
            raise ValidationError("Email address already taken")

    username = StringField(label="User Name :",validators=[Length(min=2, max=30),DataRequired()]) # to find in html   field type string
    email_address = StringField(label="Email Address :",validators=[Email(),DataRequired()])
    submit = SubmitField(label="Submit")