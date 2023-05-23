// CLI App that will query the riot games API to get player data
#include <stdio.h>
#include <useful.h>
#include <http_client.h>
#define API_KEY "RGAPI-6280fbc9-fa01-42a1-b2ff-7ff7c02610f6"

int main(int argc, char** argv){
    if(argc != 5) {
        printf("Invalid number of arguments. Please provide a summoner name, server, region, and zone.\n");
        return 1; 
    }
    char* summoner_name = argv[1];
    char* server = argv[2];
    char* region = argv[3];
    char* zone = argv[4];

    make_request(summoner_name, server, region, zone);
    return 0;
}
