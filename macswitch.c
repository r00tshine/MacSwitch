#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void check_dependencies(bool macchanger_exists)
{
  if (macchanger_exists == 0)  {
    // Carry on
  } else {
    system("apt-get install -y macchanger");
  }  
}

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
      system("pkill -f -9 macswitch");
    }
    changer(amount);
    reset();
  }
  check_dependencies(system("which macchanger > /dev/null 2>&1"));
  int amount = atoi(argv[1]);
  mac_changer(amount);
}
