#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <curl/easy.h>
#include <curl/curlbuild.h>
#include <string>
//first do:
//sudo apt-get install libcurl4-openssl-dev

//http://slides.com/uczelnia_bt_kw/pointerz#/8/3
//excercise

//implement a program that:

//uses CUrl for data downloading
//stores data in std::string
//prints size of received data

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *p) {
    ((std::string*)p)->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

class cUrlDwl{
public:
    cUrlDwl(){
        curl = curl_easy_init();
    }

    ~cUrlDwl(){
        curl_easy_cleanup(curl);
    }

    static size_t handle(char * data, size_t size, size_t nmemb, void * p);

    size_t handle_impl(char * data, size_t size, size_t nmemb);

    void dl(const std::string& url){

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); // example.com is redirected, so we tell libcurl to follow redirection
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1); //Prevent "longjmp causes uninitialized stack frame" bug
        curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
        //std::stringstream out;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data); // Perform the request, res will get the return code
        CURLcode res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
    }

    size_t size(){
        return this->data.length();
    }

private:
    void* curl;
    std::string data;
};

int main(){
    cUrlDwl downloader;
    downloader.dl(std::string("http://wp.pl"));
    std::cout << "Size of downloaded data: " << downloader.size() << " chars." << std::endl;
    return 0;
}
