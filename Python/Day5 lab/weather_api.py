import requests 



class WeatherClient:
    def __init__(self, auth_key):
        self.__setKey(auth_key)
        self.baseURL = "http://api.weatherapi.com/v1/{domain}?key={key}&q={query}"


    def get_current_temperature(self, city):
        assert isinstance(city, str), "City must be string!!"
        res = requests.get(self.baseURL.format(domain = "current.json", key =self.__key, query = city))
        print(f"The current Tempreature in {city} in Celecious is {res.json()['current']['temp_c']}C")
        print(f"The current Tempreature in {city} in Fahrenheit is {res.json()['current']['temp_f']}F\n")

    def get_temperature_after(self, city, days, hour=None):
        assert isinstance(city, str), "City must be string!!"
        assert isinstance(days, int), "Days must be integer!!"
        if hour:
            assert isinstance(hour, int), "Hour must be Integer!!"
            query = f"{city}&days={days}&hour={hour}"
        else:
            query = f"{city}&days={days}"
            hour= 0

        res = requests.get(self.baseURL.format(domain = "forecast.json", key =self.__key, query = query))

        # print(res.json()['forecast']['forecastday'][-1])
        # print(res.json()['forecast']['forecastday'][-1]['day'], "\n\n\n")
        c = res.json()['forecast']['forecastday'][-1]['hour'][0]['temp_c']
        f = res.json()['forecast']['forecastday'][-1]['hour'][0]['temp_f']

        print(f"The current Tempreature in {city} after {days} days at hour {hour} in Celecious is {c}C")
        print(f"The current Tempreature in {city} after {days} days at hour {hour} in Fahrenheit is {f}F\n")

    def get_lat_and_long(self, city):
        res = requests.get(self.baseURL.format(domain = "timezone.json", key =self.__key, query = city))
        print(f"The Latitude of {city} is {res.json()['location']['lat']}")
        print(f"The Longitude of {city} is {res.json()['location']['lon']}\n")
         
    def __setKey(self, key):
        self.__key = key

# key = input("Please enter your weather api key: ")
key = "950eccf50ac0420f8b7142247231212"
wc = WeatherClient(key)

wc.get_current_temperature("cairo")
wc.get_lat_and_long("tanta")
wc.get_temperature_after("tanta", 2, 23)
wc.get_temperature_after("tanta", 2)