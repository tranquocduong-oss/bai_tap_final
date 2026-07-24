#include <stdio.h>
#include <string.h>

typedef struct
{
    char light;
    char fan;
    char motor;
} smartHome_t;

// Dữ liệu giả lập server trả về 
const char* data =
"HTTP/1.1 200 OK\r\n"
"{"
"\"light\": \"on\","
"\"fan\": \"off\","
"\"motor\": \"off\""
"}";

//Hàm lấy trạng thái của một thiết bị 
char getStatus(const char* data, const char* device)
{
    const char* p;

    p = strstr(data, device);
    if (p == NULL)
        return 0;

    p = strchr(p, ':');
    if (p == NULL)
        return 0;

    p++;                    // Bỏ dấu :

    while (*p == ' ')       // Bỏ khoảng trắng
        p++;

    if (*p == '"')          // Bỏ dấu "
        p++;

    if (strncmp(p, "on", 2) == 0)
        return 1;

    return 0;
}

// Hàm yêu cầu của đề
smartHome_t pair_data(const char* data)
{
    smartHome_t state;

    state.light = getStatus(data, "\"light\"");
    state.fan = getStatus(data, "\"fan\"");
    state.motor = getStatus(data, "\"motor\"");

    return state;
}

int main(void)
{
    smartHome_t x = pair_data(data);

    printf("Light : %d\n", x.light);
    printf("Fan   : %d\n", x.fan);
    printf("Motor : %d\n", x.motor);

    return 0;

}