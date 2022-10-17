// api.openweathermap.org/data/2.5/weather?q={cityname}&appid={API key}
let weather = {
  apikey: "7a6305603daf106e7c93e7c269dbdb47",
  fetchWeather: function (city) {
    fetch(
      "https://api.openweathermap.org/data/2.5/weather?q=" +
        city +
        "&units=metric&appid=" +
        this.apikey
    )
      .then((response) => response.json())
      .then((data) => this.displayWeather(data));
  },
  displayWeather: function (data) {
    const { name } = data;
    const { icon, description } = data.weather[0];
    const { temp, humidity } = data.main;
    const { feels_like } = data.main;
    const { speed } = data.wind;
    const {lat} = data.coord;
    const {lon} = data.coord;
    console.log(name, icon, description, temp, humidity, speed);
    document.querySelector(".lat").innerText = "Latitude : " + lat; 
    document.querySelector(".lon").innerText = "Longitude : " + lon; 
    document.querySelector(".feels_like").innerText = "Feels Like : " + feels_like + "°C";
    document.querySelector(".city").innerText = "Weather in " + name;
    document.querySelector(".temp").innerText = temp + "°C";
    document.querySelector(".icon").src =
      "https://openweathermap.org/img/wn/" + icon + ".png";
    document.querySelector(".description").innerText = description;
    document.querySelector(".humidity").innerText =
      "Humidity : " + humidity + "%";
    document.querySelector(".wind").innerText = "Wind : " + speed + "km/hr";
    document.body.style.backgroundImage = "url('https://source.unsplash.com/random/1500x700?"+description+"')"
  },
  search: function () {
    this.fetchWeather(document.querySelector("#search-bar").value);
  },
};
document.querySelector("#btn").addEventListener("click", function () {
  weather.search();
});
document
  .querySelector("#search-bar")
  .addEventListener("keyup", function (event) {
    if (event.key == "Enter") {
      weather.search();
    }
  });

onload  = weather.fetchWeather("kolkata");
