It is necessary to instance a float variable to read an analogic value.
V2 = (Vcc./1023.)*readVal

   - The dots function is to cast. Transform an integer value to a float value.
   - Range of values of potenciometer are between 0 and 1023. Factor of conversion is needed to show a voltage value between 0 and Vcc you               supply