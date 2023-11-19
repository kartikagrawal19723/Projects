import json
import requests
import sys
def main():
    response = requests.get("https://itunes.apple.com/search?entity=song&limit=1&term=" + sys.argv[1])
    print(response)
main()