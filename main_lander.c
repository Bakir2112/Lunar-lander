#include <stdio.h>

int Control(int altitude) {
  int thruster = 0;

  // Lunar lander control logic
  if (altitude > 100)
    thruster = 0;      // Turn thruster off above 100
  else if (altitude > 0)
    thruster = 1;      // Turn thruster on between 1-100
  else
    thruster = 0;      // Turn thruster off at or below 0

  return thruster;
}

void Test(int altitude) {
  int thruster = Control(altitude);
  int behaviorCorrect = (altitude > 100 && thruster == 0) ||
                        (altitude <= 100 && altitude > 0 && thruster == 1) ||
                        (altitude <= 0 && thruster == 0);
  char *behaviorCorrectIcon = behaviorCorrect ? "✅" : "❌";
  printf("For altitude %3d, your thruster is %d |%s|\n", altitude, thruster,
         behaviorCorrectIcon);
}

int main(void) {
  printf("Testing Lunar Lander Control:\n");
  printf("=============================\n");
  
  Test(150);  // Should be ✅ (thruster=0)
  Test(100);  // Should be ✅ (thruster=1) 
  Test(50);   // Should be ✅ (thruster=1)
  Test(0);    // Should be ✅ (thruster=0)
  Test(-1);   // Should be ✅ (thruster=0)
  
  return 0;
}

