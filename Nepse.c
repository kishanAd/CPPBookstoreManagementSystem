#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// size_t get_data(char *buffer, size_t itemsize, size_t nitems, void *userdata)
// {
//   size_t bytes = itemsize * nitems;
//   printf("New chunk : {%zu}\n", bytes);
//   int linenumber = 1;
//   printf("%d\n", linenumber);
//   for (int i = 0; i < bytes; i++)
//   {
//     if (buffer[i] == '\n')
//     {
//       linenumber++;
//       printf("%d\n", linenumber);
//     }
//   }
//   // FILE *fp = (FILE *)userdata;
//   // fwrite(buffer, itemsize, nitems, fp);
//   return bytes;
// }

int main()
{
  char url[300] = "https://nepse-data-api.herokuapp.com/data/todaysprice";
  FILE *fp;
  fp = fopen("nepse.json", "wb");
  CURL *curl = curl_easy_init();

  if (!curl)
  {
    fprintf(stderr, "curl_easy_init() failed\n");
    return 1;
  }
  curl_easy_setopt(curl, CURLOPT_URL, url);
  // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK)
  {
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    return 1;
  }
  return 0;
}