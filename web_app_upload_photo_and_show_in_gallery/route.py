

from ourapp import app
from flask import render_template, redirect, url_for , request, flash, get_flashed_messages
from ourapp import db
from ourapp.models import User
from ourapp.forms import Userform
import os




@app.route("/")

@app.route("/home")
def home_page():
    return render_template("home.html")

@app.route("/aboutus")
def aboutus_page():
    return render_template("aboutus.html")

@app.route("/gallery")
def gallery_page():
    pics = User.query.all()
    return render_template("gallery.html", pics=pics)

@app.route("/upload",methods=["GET","POST"])
def upload_page():
    form = Userform()
    if form.validate_on_submit(): # submission
        
        pic = request.files['pic']  # should get a from  normal wtf cannot read image
        imagefilename= pic.filename
        pic.save(os.path.join(app.config["UPLOAD_FOLDER"],imagefilename))

        user_to_create = User(username=form.username.data, email_address=form.email_address.data,filename=imagefilename) # add to database
        db.session.add(user_to_create)
        db.session.commit()
        return redirect(url_for("gallery_page"))

    if form.errors != {}: #If there are not errors from the validations
        for err_msg in form.errors.values():
            flash(f'There was an error with creating a user: {err_msg}', category='danger')

    return render_template("upload.html",form=form)



