

int IRTCGetTime12(char[], int);
int IRTCGetTime24(char[], int);
void IRTCGetDate(char[], int, char[], int);
int IRTCSetTime24(int hour, int minutes, int seconds);
void IRTCSetTime12(int hour, int minutes, int seconds, int pm);
void IRTCSetDate(int date, int month, int year);