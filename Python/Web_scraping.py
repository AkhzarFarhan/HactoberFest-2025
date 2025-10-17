\import requests
from bs4 import BeautifulSoup

def scrape_titles(url):
    # Send a GET request to the specified URL
    response = requests.get(url)

    # Check if the request was successful
    if response.status_code == 200:
        # Parse the HTML content of the page
        soup = BeautifulSoup(response.content, 'html.parser')

        # Find all article titles on the page (adjust the selector based on the website)
        titles = soup.find_all('h2')  # Assuming article titles are in <h2> tags

        # Print the titles
        for index, title in enumerate(titles, start=1):
            print(f"{index}: {title.get_text(strip=True)}")
    else:
        print("Failed to retrieve the webpage.")

# Example usage
if __name__ == "__main__":
    url = 'https://example.com/articles'  # Replace with the URL of the desired website
    scrape_titles(url)
  
