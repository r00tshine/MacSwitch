#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  void mac_changer(int amount)
  {
    
    void changer(int j)
    {
      int i;
      for (i = 1;i <= j;i++) {
        printf("[MacSwitch] Your MAC Address has changed. You have the current one for 1 minute.\n");
        system("ifconfig wlan0 down && macchanger -r wlan0 >/dev/null && ifconfig wlan0 up && sleep 1m;");
      }
    }
    void reset()
    {
      system("ifconfig wlan0 down && macchanger -p wlan0 >/dev/null && ifconfig wlan0 up");
      printf("[MacSwitch] Your MAC Address has been reset!\n");
      system("pkill -f -9 switchdamac");
    }
    changer(amount);
    reset();
  }
  int amount = atoi(argv[1]);
  mac_changer(amount);
}
