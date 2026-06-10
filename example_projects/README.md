# example_projects information
日本語版は[こちら](./READMEJP.md)
 <br>
 
This directory provides basic example projects for RL78 peripheral modules such as TAU, SAU, and ADC.<br>
Each project demonstrates the most fundamental usage of a single peripheral, allowing users to understand its behavior and configuration in isolation.<br>
These projects are intended as reference examples and starting points for development, rather than complete applications.
 <br>
 <br>
This README.md introduces the projects available for each RL78 device.
 <br>
 
## Content
- [RL78/G2x](#rl78g2x)

## RL78/G2x
- [RL78/G22](#rl78g22)
- [RL78/G23](#rl78g23)
- [RL78/G24](#rl78g24)

### RL78/G22
| Peripheral | Folder | Description |
|---|---|---|
| ADC | [ADC Software Trigger Scan Mode](./rl78_g2x/rl78_g22/adc_software_trigger_scan_conversion_modes) | RL78/G22 ADC software trigger and scan conversion modes example |
| ADC | [ADC Software Trigger Sequential Mode](./rl78_g2x/rl78_g22/adc_software_trigger_sequential_conversion_modes) | RL78/G22 ADC software trigger and sequential conversion modes example |
| TAU | [Interval Timer](./rl78_g2x/rl78_g22/interval_timer) | RL78/G22 interval timer example |
| TAU | [Pulse Interval Measurement (Period)](./rl78_g2x/rl78_g22/pulse_interval_measurement_period) | RL78/G22 pulse interval measurement (period) example |
| TAU | [Pulse Interval Measurement (Width)](./rl78_g2x/rl78_g22/pulse_interval_measurement_width) | RL78/G22 pulse interval measurement (width) example |
| TAU | [PWM Output](./rl78_g2x/rl78_g22/pwm_output) | RL78/G22 PWM output example |
| Timer | [32-bit Interval Timer](./rl78_g2x/rl78_g22/32-bit_interval_timer) | RL78/G22 32-bit interval timer example |
| SAU | [UART](./rl78_g2x/rl78_g22/uart) | RL78/G22 UART example |
| Serial Interface | [IICA Slave](./rl78_g2x/rl78_g22/iica_slave) | RL78/G22 IICA for slave example |
| Serial Interface | [IICA Master](./rl78_g2x/rl78_g22/iica_master) | RL78/G22 IICA for master example |
| Serial Interface | [UARTA](./rl78_g2x/rl78_g22/uarta) | RL78/G22 UARTA example |

### RL78/G23
| Peripheral | Folder | Description |
|---|---|---|
| ADC | [ADC Scan Mode](./rl78_g2x/rl78_g23/adc_scan_mode) | RL78/G23 ADC scan mode (in addition to sequential conversion mode and software trigger no-wait mode) example |
| ADC | [ADC Software Trigger Wait Mode](./rl78_g2x/rl78_g23/adc_software_trigger_wait_mode) | RL78/G23 ADC software trigger wait mode (in addition to select mode and one-shot conversion mode) example |
| TAU | [Interval Timer](./rl78_g2x/rl78_g23/interval_timer) | RL78/G23 interval timer example |
| TAU | [Pulse Interval Measurement (Period)](./rl78_g2x/rl78_g23/pulse_interval_measurement_period) | RL78/G23 pulse interval measurement (period) example |
| TAU | [Pulse Interval Measurement (Width)](./rl78_g2x/rl78_g23/pulse_interval_measurement_width) | RL78/G23 pulse interval measurement (width) example |
| TAU | [PWM Output](./rl78_g2x/rl78_g23/pwm_output) | RL78/G23 PWM output example |
| Timer | [32-bit Interval Timer](./rl78_g2x/rl78_g23/32-bit_interval_timer) | RL78/G23 32-bit interval timer example |
| RTC | [Realtime Clock](./rl78_g2x/rl78_g23/realtime_clock) | RL78/G23 realtime clock example |
| SAU | [UART](./rl78_g2x/rl78_g23/uart) | RL78/G23 UART example |
| Serial Interface | [UARTA](./rl78_g2x/rl78_g23/uarta) | RL78/G23 UARTA example |

### RL78/G24
| Peripheral | Folder | Description |
|---|---|---|
| ADC | [ADC Advanced Mode Enaled](./rl78_g2x/rl78_g24/adc_advanced_mode_enabled) | RL78/G24 ADC Advanced mode enabled example |
| ADC | [ADC Advanced Mode disaled](./rl78_g2x/rl78_g24/adc_advanced_mode_disabled) | RL78/G24 ADC Advanced mode disabled example |
| TAU | [Interval Timer](./rl78_g2x/rl78_g24/interval_timer) | RL78/G24 interval timer example |
| TAU | [Pulse Interval Measurement (Period)](./rl78_g2x/rl78_g24/pulse_interval_measurement_period) | RL78/G24 pulse interval measurement (period) example |
| TAU | [Pulse Interval Measurement (Width)](./rl78_g2x/rl78_g24/pulse_interval_measurement_width) | RL78/G24 pulse interval measurement (width) example |
| TAU | [PWM Output](./rl78_g2x/rl78_g24/pwm_output) | RL78/G24 PWM output example |
| Timer | [32-bit Interval Timer](./rl78_g2x/rl78_g24/32-bit_interval_timer) | RL78/G24 32-bit interval timer example |
| Timer | [Timer RD2 Input Capture Function and Output Compare Function](./rl78_g2x/rl78_g24/timer_rd2_input_capture_function_output_compare_function) | RL78/G24 Timer RD2 input capture function and output compare function example |
| Timer | [Timer RD2 Timer Mode PWM Function](./rl78_g2x/rl78_g24/timer_rd2_timer_mode_pwm_function) | RL78/G24 Timer RD2 timer mode PWM function example |
| Timer | [Timer RG2 Buffer Operation PWM Mode](./rl78_g2x/rl78_g24/timer_rg2_buffer_operation_pwm_mode) | RL78/G24 Timer RG2 buffer operation PWM mode example |
| Timer | [Timer RG2 Phase Counting Mode](./rl78_g2x/rl78_g24/timer_rg2_phase_counting_mode) | RL78/G24 Timer RG2 phase counting mode example |
| RTC | [Realtime Clock](./rl78_g2x/rl78_g24/realtime_clock) | RL78/G24 realtime clock example |
| SAU | [UART](./rl78_g2x/rl78_g24/uart) | RL78/G24 UART example |
