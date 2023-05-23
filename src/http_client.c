#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "http_client.h"
#include <curl/curl.h>

#define API_KEY "RGAPI-c8b91e5e-8442-4771-b732-4d80e1cf8aba"

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    printf("%s\n", (char*)contents);
    return realsize;
}


void make_request(const char* summoner_name, const char* server, const char* region, const char* zone) {
    
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        // Construct the URL
        char url[256]; // Make sure this is large enough to hold your entire URL
        sprintf(url, "https://%s.api.riotgames.com/lol/summoner/v4/summoners/by-name/%s?api_key=%s", server, summoner_name, API_KEY);

        curl_easy_setopt(curl, CURLOPT_URL, url);

        // If you want libcurl to follow HTTP redirects (status code 3xx), uncomment the following line
        // curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Send all data to this function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    
    // Construct the URL
    // char url[256]; // Make sure this is large enough to hold your entire URL
    // sprintf(url, "https://%s.api.riotgames.com/lol/summoner/v4/summoners/by-name/%s?api_key=%s", server, summoner_name, API_KEY);

    // TODO: Make the HTTP request using your chosen library/method
    // This will depend on what libraries you have available and how you want to handle the request

}
