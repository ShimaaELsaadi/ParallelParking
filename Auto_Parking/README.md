# Parallel-Parking
<h3>Hardware Components:</h3>
ATmega32<br>
4 Ultrasonic Sensors<br>
2 DC Motors<br>
H-bridge<br>

<h3>Software Components:</h3>
Application: Auto Parking<br>
Hardware Abstraction Layer (HAL): Ultrasonic, DC Motor control<br>
Microcontroller Abstraction Layer (MCAL): GPIO, Timer1 (ICU), Timer (PWM)<br>

<h3>Project Phases - The State Machine:</h3>

📌State 1 - Forward Motion: The car moves forward while utilizing the side ultrasonic sensors to detect an empty parking slot.<br>

📌State 2 - Parking Mode: Once the car identifies an available parking spot, it seamlessly transitions into parking mode, employing all four ultrasonic sensors for precise maneuvering.<br>

📌State 3 - Position Adjustment: The car adjusts its position within the parking spot, ensuring a perfect parallel park.<br>



https://github.com/EsraaAhmed252/Parallel-Parking/assets/99142254/1dfaf639-41f9-41ef-a5a2-33f302bbe9bb

