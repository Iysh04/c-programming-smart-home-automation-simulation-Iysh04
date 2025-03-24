/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 #define MAX_ROOMS 5   //   max number of rooms
 
 // Function prototypes
 void initializeSystem(int rooms, int light[], int temp[], int Motion[], int security[]);
 void displayMenu();
 void controlLights(int rooms, int light[]);
 void readTemperature(int rooms, int temp[]);
 void detectMotion(int rooms, int Motion[]);
 void securitySystem(int rooms, int security[]);
 void analyzeHouseStatus(int rooms, int light[], int temp[], int Motion[], int security[]);
 
 int main() {
     int rooms;
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
     if (rooms < 1 || rooms > MAX_ROOMS) {
         printf("PLEASE ENTER A VALID NUMBER !!\n");
         return 1;
     }
 
     int light[rooms], temp[rooms], Motion[rooms], security[rooms];
 
     initializeSystem(rooms, light, temp, Motion, security);
 
     int choice;
     do {
         displayMenu();
         printf("Enter your choice:");
         scanf("%d", &choice);
         switch (choice) {
             case 1:
                 controlLights(rooms, light);
                 break;
             case 2:
                 readTemperature(rooms, temp);
                 break;
             case 3:
                 detectMotion(rooms, Motion);
                 break;
             case 4:
                 securitySystem(rooms, security);
                 break;
             case 5:
                 analyzeHouseStatus(rooms, light, temp, Motion, security);
                 break;
             case 6:
                 printf("EXIT !!!!\n");
                 break;
             default:
                 printf("Invalid choice. Please try again.\n");
         }
     } while (choice != 6);
 
     return 0;
 }
 
 
 void initializeSystem(int rooms, int light[], int temp[], int Motion[], int security[]) {
     for (int i = 0; i < rooms; i++) {
         light[i] = 0;
         temp[i] = 22;
         Motion[i] = 0;
         security[i] = 0;
     }
 }
 
 void displayMenu() {
     printf("\n===== Smart Home Menu =====\n");
     printf("1. Toggle Light\n");
     printf("2. Read Temperature\n");
     printf("3. Check Motion Sensor\n");
     printf("4. Lock/Unlock Security System\n");
     printf("5. House Status Summary\n");
     printf("6. Exit\n");
 
 }
 
 void controlLights(int rooms, int light[]) {
     int room;
     printf("Enter room number to toggle light (1-%d): ", rooms);
     scanf("%d", &room);
 
     if (room < 1 || room > rooms) {
         printf("PLEASE ENTER A VALID NUMBER !!\n");
         return;
     }
 
     light[room - 1] = !light[room - 1]; // Toggle the light status
 
     if (light[room - 1] == 1) {
         printf("LIGHTS IN ROOM %d ARE ON NOW !!\n", room);
     } else {
         printf("LIGHTS IN ROOM %d ARE OFF NOW !!\n", room);
     }
 
 }
 void readTemperature(int rooms, int temp[]) {
     int room;
     printf("Enter room number to read temperature (1-%d): ", rooms);
     scanf("%d", &room);
 
     if (room < 1 || room > rooms) {
         printf("PLEASE ENTER A VALID NUMBER !!\n");
         return;
     }
 
     printf("TEMPERATURE OF ROOM %d is %d degrees Celsius\n", room, temp[room - 1]);
 
 
 }
 
 void detectMotion(int rooms, int Motion[]) {
     int room;
     printf("Enter room number to check motion (1-%d): ", rooms);
     scanf("%d", &room);
 
     if (room < 1 || room > rooms) {
         printf("PLEASE ENTER A VALID NUMBER !!\n");
         return;
     }
 
     Motion[room - 1] = !Motion[room - 1]; // Toggle motion detection status
 
     if (Motion[room - 1] == 0) {
         printf("NO MOTION DETECTED IN ROOM %d !!\n", room);
     } else {
         printf("MOTION DETECTED IN ROOM %d !!\n", room);
     }
 
 }
 void securitySystem(int rooms, int security[]) {
     int room;
     printf("Enter room number to lock/unlock security (1-%d): ", rooms);
     scanf("%d", &room);
 
     if (room < 1 || room > rooms) {
         printf("PLEASE ENTER A VALID NUMBER !!\n");
         return;
     }
 
     security[room - 1] = !security[room - 1]; // Toggle security status
 
     if (security[room - 1] == 0) {
         printf("SECURITY SYSTEM IN ROOM %d IS UNLOCKED !!\n", room);
     } else {
         printf("SECURITY SYSTEM IN ROOM %d IS LOCKED !!\n", room);
     }
 
 }
 void analyzeHouseStatus(int rooms, int light[], int temp[], int Motion[], int security[]) {
     printf("\n===== House Status Summary =====\n");
     for (int i = 0; i < rooms; i++) {
         printf("ROOM %d: ", i + 1);
         printf("Lights: %s, ", light[i] ? "ON" : "OFF");
         printf("Temperature: %d C, ", temp[i]);
         printf("Motion: %s, ", Motion[i] ? "Detected" : "Not Detected");
         printf("Security: %s\n", security[i] ? "Locked" : "Unlocked");
     }
     printf("===============================\n");
 }
