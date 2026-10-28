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
- [RL78/L2x](#rl78l2x)

## RL78/G2x
- [RL78/G21](#rl78g21)
- [RL78/G22](#rl78g22)
- [RL78/G23](#rl78g23)
- [RL78/G24](#rl78g24)

### RL78/G21
| Peripheral | Folder | Description |
|---|---|---|
| Quick Start | [Quick Start](./rl78_g2x/rl78_g21/quickstart) | RL78/G21 LED blinky example |
| ADC | [AD Converter](./rl78_g2x/rl78_g21/adc) | RL78/G21 AD converter example |
| TAU | [Timer Array Unit](./rl78_g2x/rl78_g21/tau) | RL78/G21 timer array unit example |
| SAU | [I2C](./rl78_g2x/rl78_g21/sau_i2c_master) | RL78/G21 I2C example |
| SAU | [SPI](./rl78_g2x/rl78_g21/sau_spi_master) | RL78/G21 SPI example |
| SAU | [UART](./rl78_g2x/rl78_g21/sau_uart_master) | RL78/G21 UART example |
| Serial Interface | [UARTA](./rl78_g2x/rl78_g21/uarta) | RL78/G21 UARTA example |
| Serial Interface | [IICA Master](./rl78_g2x/rl78_g21/iic_master_iica) | RL78/G21 IICA for master example |

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
| Clock | [HOCO Frequency Correction](./rl78_g2x/rl78_g22/hoco_clock_frequency_correction) |RL78/G22 HOCO clock frequency correction example |
| SAU | [UART](./rl78_g2x/rl78_g22/uart) | RL78/G22 UART example |
| Serial Interface | [IICA Slave](./rl78_g2x/rl78_g22/iica_slave) | RL78/G22 IICA for slave example |
| Serial Interface | [IICA Master](./rl78_g2x/rl78_g22/iica_master) | RL78/G22 IICA for master example |

### RL78/G23
| Peripheral | Folder | Description |
|---|---|---|
| Quick Start | [Quick Start](./rl78_g2x/rl78_g23/ep_quickstart) | RL78/G23 LED blinky example |
| ADC | [ADC Scan Mode](./rl78_g2x/rl78_g23/adc_scan_mode) | RL78/G23 ADC scan mode (in addition to sequential conversion mode and software trigger no-wait mode) example |
| ADC | [ADC Software Trigger Wait Mode](./rl78_g2x/rl78_g23/adc_software_trigger_wait_mode) | RL78/G23 ADC software trigger wait mode (in addition to select mode and one-shot conversion mode) example |
| ADC | [EP ADC](./rl78_g2x/rl78_g23/ep_adc) | RL78/G23 ADC window compare mode example project |
| TAU | [Interval Timer](./rl78_g2x/rl78_g23/interval_timer) | RL78/G23 interval timer example |
| TAU | [Pulse Interval Measurement (Period)](./rl78_g2x/rl78_g23/pulse_interval_measurement_period) | RL78/G23 pulse interval measurement (period) example |
| TAU | [Pulse Interval Measurement (Width)](./rl78_g2x/rl78_g23/pulse_interval_measurement_width) | RL78/G23 pulse interval measurement (width) example |
| TAU | [PWM Output](./rl78_g2x/rl78_g23/pwm_output) | RL78/G23 PWM output example |
| TAU | [EP Timer Array Unit](./rl78_g2x/rl78_g23/ep_tau) | RL78/G23 timer array unit example project |
| Timer | [32-bit Interval Timer](./rl78_g2x/rl78_g23/32-bit_interval_timer) | RL78/G23 32-bit interval timer example |
| Clock | [CPU Clock Changing and Standby Settings](./rl78_g2x/rl78_g23/cpu_clock_changing_standby_settings) | RL78/G23 clock changing and standby settings example |
| Clock | [HOCO Frequency Correction](./rl78_g2x/rl78_g23/hoco_frequency_correction) | RL78/G23 HOCO clock frequency correction example |
| Clock | [MOCO Frequency Correction](./rl78_g2x/rl78_g23/moco_frequency_correction) | RL78/G23 MOCO clock frequency correction example |
| Clock | [LOCO Frequency Correction](./rl78_g2x/rl78_g23/loco_frequency_correction) | RL78/G23 LOCO clock frequency correction example |
| RTC | [Realtime Clock](./rl78_g2x/rl78_g23/realtime_clock) | RL78/G23 realtime clock example |
| SAU | [UART](./rl78_g2x/rl78_g23/uart) | RL78/G23 UART example |
| SAU | [Handshake SPI Master](./rl78_g2x/rl78_g23/handshake_based_spi_master_transmission_reception) | RL78/G23 handshake SPI master example |
| SAU | [Handshake SPI Slave](./rl78_g2x/rl78_g23/handshake_based_spi_slave_transmission_reception) | RL78/G23 handshake SPI slave example |
| SAU | [I2C Multiple Slave Address (Master)](./rl78_g2x/rl78_g23/i2c_supporting_multiple_slave_address_master) | RL78/G23 I2C multiple slave address master example|
| SAU | [I2C Multiple Slave Address (Slave)](./rl78_g2x/rl78_g23/i2c_supporting_multiple_slave_address_slave) | RL78/G23 I2C multiple slave address slave example |
| SAU | [EP I2C](./rl78_g2x/rl78_g23/ep_sau_i2c_master) | RL78/G23 I2C example project |
| SAU | [EP SPI](./rl78_g2x/rl78_g23/ep_sau_spi_master) | RL78/G23 SPI example project |
| SAU | [EP UART](./rl78_g2x/rl78_g23/ep_sau_uart_master) | RL78/G23 UART example project |
| Serial Interface | [UARTA](./rl78_g2x/rl78_g23/uarta) | RL78/G23 UARTA example |
| Serial Interface | [UART Reception in STOP Mode](./rl78_g2x/rl78_g23/uart_reception_stop_mode_using_uarta) | RL78/G23 UART reception in STOP mode example |
| Serial Interface | [EP UARTA](./rl78_g2x/rl78_g23/ep_uarta) | RL78/G23 UARTA example project |
| Serial Interface | [EP IICA Master](./rl78_g2x/rl78_g23/ep_iic_master_iica) | RL78/G23 IICA for master example project |
| Power Management | [Operation State Switching](./rl78_g2x/rl78_g23/operation_state_switching) | RL78/G23 operation state switching example |
| Power Management | [Using VBAT Pin](./rl78_g2x/rl78_g23/using_vbat_pin) | RL78/G23 VBAT pin example |
| Port | [Output Current Control Ports](./rl78_g2x/rl78_g23/output_current_control_ports) | RL78/G23 output current control ports example |
| Port | [40mA Port Output](./rl78_g2x/rl78_g23/40ma_port_output) | RL78/G23 40mA port output example |
| Comparator | [Window Comparator](./rl78_g2x/rl78_g23/setting_window_comparator) | RL78/G23 window comparator example |
| LVD | [Voltage Detector](./rl78_g2x/rl78_g23/voltage_detector) | RL78/G23 voltage detector example |

### RL78/G24
| Peripheral | Folder | Description |
|---|---|---|
| ADC | [ADC Advanced Mode Enaled](./rl78_g2x/rl78_g24/adc_advanced_mode_enabled) | RL78/G24 ADC Advanced mode enabled example |
| ADC | [ADC Advanced Mode disaled](./rl78_g2x/rl78_g24/adc_advanced_mode_disabled) | RL78/G24 ADC Advanced mode disabled example |
| Timer | [Timer RD2 Input Capture Function and Output Compare Function](./rl78_g2x/rl78_g24/timer_rd2_input_capture_function_output_compare_function) | RL78/G24 Timer RD2 input capture function and output compare function example |
| Timer | [Timer RD2 Timer Mode PWM Function](./rl78_g2x/rl78_g24/timer_rd2_timer_mode_pwm_function) | RL78/G24 Timer RD2 timer mode PWM function example |
| Timer | [Timer Window Output](./rl78_g2x/rl78_g24/timer_window_output_timer_rd2_timer_array_unit_comparator) | RL78/G24 timer window output example |
| Timer | [Timer RG2 Buffer Operation PWM Mode](./rl78_g2x/rl78_g24/timer_rg2_buffer_operation_pwm_mode) | RL78/G24 Timer RG2 buffer operation PWM mode example |
| Timer | [Timer RG2 Phase Counting Mode](./rl78_g2x/rl78_g24/timer_rg2_phase_counting_mode) | RL78/G24 Timer RG2 phase counting mode example |

## RL78/L2x
- [RL78/L23](#rl78l23)

### RL78/L23
| Peripheral | Folder | Description |
|---|---|---|
| LCD | [24H Clock](./rl78_l2x/rl78_l23/24_hour_clock_displayed_lcd) | RL78/L23 LCD controller/driver 24-hour clock display example |
| LCD | [Display Clock](./rl78_l2x/rl78_l23/lcd_display_clock_demo) | RL78/L23 LCD clock display using RTC and touch buttons example |
| LCD | [Display Temperature](./rl78_l2x/rl78_l23/lcd_display_temperature_display_demo) | RL78/L23 LCD temperature display using touch buttons example |
| Bank Swap | [Bank Swapping](./rl78_l2x/rl78_l23/bank_swapping_demo) | RL78/L23 bank swap function example |
