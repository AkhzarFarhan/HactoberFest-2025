import requests
import time
from datetime import datetime
import sys

# ----------------- CONFIG -----------------
API_KEY = "your_openweathermap_api_key"  # Get free API key from openweathermap.org
CITY = "London"
UNIT = "metric"  # metric -> Celsius, imperial -> Fahrenheit
CHECK_HOUR = 8  # 24-hour format, e.g., 8 AM
CHECK_MINUTE = 0
# ------------------------------------------

def get_weather(city: str):
    """Fetch current weather from OpenWeatherMap API."""
    url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&units={UNIT}&appid={API_KEY}"
    try:
        response = requests.get(url)
        data = response.json()
        if response.status_code != 200:
            print(f"Error: {data.get('message','Unknown error')}")
            return None
        weather = data['weather'][0]['description']
        temp = data['main']['temp']
        feels_like = data['main']['feels_like']
        humidity = data['main']['humidity']
        return f"Weather in {city}: {weather}, Temp: {temp}°C, Feels like: {feels_like}°C, Humidity: {humidity}%"
    except Exception as e:
        print("Error fetching weather:", e)
        return None

def send_notification(message: str):
    """Simple print notification. Can be extended to system notifications."""
    print(f"\n📢 Weather Reminder ({datetime.now().strftime('%Y-%m-%d %H:%M')}):\n{message}\n")

def main():
    print(f"Weather Reminder started for {CITY}. Will check daily at {CHECK_HOUR:02d}:{CHECK_MINUTE:02d}.")
    while True:
        now = datetime.now()
        if now.hour == CHECK_HOUR and now.minute == CHECK_MINUTE:
            weather_info = get_weather(CITY)
            if weather_info:
                send_notification(weather_info)
            # Wait 60 seconds to avoid multiple triggers within the same minute
            time.sleep(60)
        time.sleep(10)

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nWeather Reminder stopped by user.")
        sys.exit(0)
