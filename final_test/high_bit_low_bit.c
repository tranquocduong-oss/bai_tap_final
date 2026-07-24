#include <stdio.h>

void ham_tach_bit(unsigned short val) {
    // Tách 8 bit cao bằng cách dịch phải 8 bit và lấy phần dư cho 0xFF
    unsigned char high = (val >> 8) & 0xFF;

    // Tách 8 bit thấp bằng cách lấy phần dư cho 0xFF
    unsigned char low = val & 0xFF;

    // In kết quả 
    printf("So nguyen: %d (0x%04X)\n", val, val);
    printf("8 bit cao: %d (0x%02X)\n", high, high);
    printf("8 bit thap: %d (0x%02X)\n", low, low);
}

int main() {
    // Ví dụ kiểm tra với số 1234 (0x04D2)
    unsigned short test_val = 1234;
    ham_tach_bit(test_val);

    return 0;
}