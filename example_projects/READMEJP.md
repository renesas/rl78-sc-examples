# example_projects information
English page is [here](./README.md).<br>
 <br>
このディレクトリでは、TAU、SAU、ADC などのRL78周辺機能を対象とした基本的なExample Projectsを提供しています。<br>
各プロジェクトは単一の周辺機能の最も基本的な使い方を示しており、その動作や設定を個別に理解できるようになっています。<br>
これらのプロジェクトは、完成されたアプリケーションではなく、リファレンス例や開発を始めるための出発点としての利用を想定しています。
 <br>
 <br>
このREADMEでは、RL78の各デバイスについて利用可能なプロジェクトを紹介します。
 <br>
 
## 目次
- [RL78/G2x](#rl78g2x)
- [RL78/L2x](#rl78l2x)

## RL78/G2x
- [RL78/G21](#rl78g21)
- [RL78/G22](#rl78g22)
- [RL78/G23](#rl78g23)
- [RL78/G24](#rl78g24)

### RL78/G21
| カテゴリ | フォルダ | 概要 |
|---|---|---|
| Quick Start | [Quick Start](./rl78_g2x/rl78_g21/quickstart) | RL78/G21のLED blinkyを行うプロジェクトです。 |
| ADC | [AD Converter](./rl78_g2x/rl78_g21/adc) | RL78/G21のA/Dコンバータを使用するプロジェクトです。 |
| TAU | [Timer Array Unit](./rl78_g2x/rl78_g21/tau) | RL78/G21のTAUを使用するプロジェクトです。 |
| SAU | [I2C](./rl78_g2x/rl78_g21/sau_i2c_master) | RL78/G21のSAUによるI2C通信を使用するプロジェクトです。 |
| SAU | [SPI](./rl78_g2x/rl78_g21/sau_spi_master) | RL78/G21のSAUによるSPI通信を使用するプロジェクトです。 |
| SAU | [UART](./rl78_g2x/rl78_g21/sau_uart_master) | RL78/G21のUARTによるSPI通信を使用するプロジェクトです。 |
| Serial Interface | [UARTA](./rl78_g2x/rl78_g21/uarta) | RL78/G21のシリアル・インターフェースUARTAを使用するプロジェクトです。 |
| Serial Interface | [IICA Master](./rl78_g2x/rl78_g21/iic_master_iica) | RL78/G21のシリアル・インターフェースIICA(マスタ送受信)を使用するプロジェクトです。 |

### RL78/G22
| カテゴリ | フォルダ | 概要 |
|---|---|---|
| ADC | [ADC Software Trigger Scan Mode](./rl78_g2x/rl78_g22/adc_software_trigger_scan_conversion_modes) | RL78/G22のA/Dコンバータをソフトウェア・トリガ、スキャンモードで使用するプロジェクトです。|
| ADC | [ADC Software Trigger Sequential Mode](./rl78_g2x/rl78_g22/adc_software_trigger_sequential_conversion_modes) | RL78/G22のA/Dコンバータをソフトウェア・トリガ、連続変換モードで使用するプロジェクトです。|
| TAU | [Interval Timer](./rl78_g2x/rl78_g22/interval_timer) | RL78/G22のTAUによるインターバル・タイマ機能を使用するプロジェクトです。 |
| TAU | [Pulse Interval Measurement (Period)](./rl78_g2x/rl78_g22/pulse_interval_measurement_period) | RL78/G22のTAUによるパルス間隔測定(周期)機能を使用するプロジェクトです。 |
| TAU | [Pulse Interval Measurement (Width)](./rl78_g2x/rl78_g22/pulse_interval_measurement_width) | RL78/G22のTAUによるパルス間隔測定(幅)機能を使用するプロジェクトです。 |
| TAU | [PWM Output](./rl78_g2x/rl78_g22/pwm_output) | RL78/G22のTAUによるPWM出力機能を使用するプロジェクトです。 |
| Timer | [32-bit Interval Timer](./rl78_g2x/rl78_g22/32-bit_interval_timer) | RL78/G22の32ビット・インターバル・タイマを使用するプロジェクトです。 |
| Clock | [HOCO Frequency Correction](./rl78_g2x/rl78_g22/hoco_clock_frequency_correction) | RL78/G22のHOCO周波数補正を行うプロジェクトです。 |
| SAU | [UART](./rl78_g2x/rl78_g22/uart) | RL78/G22のSAUによるUART通信を使用するプロジェクトです。 |
| Serial Interface | [IICA Slave](./rl78_g2x/rl78_g22/iica_slave) | RL78/G22のシリアル・インターフェースIICA(スレーブ送受信)を使用するプロジェクトです。 |
| Serial Interface | [IICA Master](./rl78_g2x/rl78_g22/iica_master) | RL78/G22のシリアル・インターフェースIICA(マスタ送受信)を使用するプロジェクトです。 |

### RL78/G23
| カテゴリ | フォルダ | 概要 |
|---|---|---|
| Quick Start | [Quick Start](./rl78_g2x/rl78_g23/ep_quickstart) | RL78/G23のLED blinkyを行うExample Projectです。 |
| ADC | [ADC Scan Mode](./rl78_g2x/rl78_g23/adc_scan_mode) | RL78/G23のA/Dコンバータをスキャンモード(ソフトウェア・トリガ・ノーウェイト・モード、連続変換モード)で使用するプロジェクトです。 |
| ADC | [ADC Software Trigger Wait Mode](./rl78_g2x/rl78_g23/adc_software_trigger_wait_mode) | RL78/G23のA/Dコンバータをソフトウェア・トリガ・ウェイト・モード(セレクト・モード、ワンショット変換モード)で使用するプロジェクトです。|
| ADC | [EP ADC](./rl78_g2x/rl78_g23/ep_adc) | RL78/G23のADCウィンドウ・コンペア・モードを使用するExample Projectです。 |
| TAU | [Interval Timer](./rl78_g2x/rl78_g23/interval_timer) | RL78/G23のTAUによるインターバル・タイマ機能を使用するプロジェクトです。 |
| TAU | [Pulse Interval Measurement (Period)](./rl78_g2x/rl78_g23/pulse_interval_measurement_period) | RL78/G23のTAUによるパルス間隔測定(周期)機能を使用するプロジェクトです。 |
| TAU | [Pulse Interval Measurement (Width)](./rl78_g2x/rl78_g23/pulse_interval_measurement_width) | RL78/G23のTAUによるパルス間隔測定(幅)機能を使用するプロジェクトです。 |
| TAU | [PWM Output](./rl78_g2x/rl78_g23/pwm_output) | RL78/G23のTAUによるPWM出力機能を使用するプロジェクトです。 |
| TAU | [EP Timer Array Unit](./rl78_g2x/rl78_g23/ep_tau) | RL78/G23のTAUを使用するExample Projectです。 |
| Timer | [32-bit Interval Timer](./rl78_g2x/rl78_g23/32-bit_interval_timer) | RL78/G23の32ビット・インターバル・タイマを使用するプロジェクトです。 |
| Clock | [CPU Clock Changing and Standby Settings](./rl78_g2x/rl78_g23/cpu_clock_changing_standby_settings) | RL78/G23のクロック切り替えとスタンバイ設定をするプロジェクトです。 |
| Clock | [HOCO Frequency Correction](./rl78_g2x/rl78_g23/hoco_clock_frequency_correction) | RL78/G23のHOCO周波数補正を行うプロジェクトです。 |
| Clock | [MOCO Frequency Correction](./rl78_g2x/rl78_g23/moco_clock_frequency_correction) | RL78/G23のMOCO周波数補正を行うプロジェクトです。 |
| Clock | [LOCO Frequency Correction](./rl78_g2x/rl78_g23/loco_clock_frequency_correction) | RL78/G23のLOCO周波数補正を行うプロジェクトです。 |
| RTC | [Realtime Clock](./rl78_g2x/rl78_g23/realtime_clock) | RL78/G23のリアルタイム・クロックを使用するプロジェクトです。 |
| SAU | [UART](./rl78_g2x/rl78_g23/uart) | RL78/G23のSAUによるUART通信を使用するプロジェクトです。 |
| SAU | [Handshake SPI Master](./rl78_g2x/rl78_g23/handshake_based_spi_master_transmission_reception) | RL78/G23のハンドシェイク対応SPIマスタ送受信を行うプロジェクトです。 |
| SAU | [Handshake SPI Slave](./rl78_g2x/rl78_g23/handshake_based_spi_slave_transmission_reception) | RL78/G23のハンドシェイク対応SPIスレーブ送受信を行うプロジェクトです。 |
| SAU | [I2C Multiple Slave Address (Master)](./rl78_g2x/rl78_g23/i2c_supporting_multiple_slave_address_master) | RL78/G23の複数スレーブ・アドレス対応I2C (マスタ)を行うプロジェクトです。 |
| SAU | [I2C Multiple Slave Address (Slave)](./rl78_g2x/rl78_g23/i2c_supporting_multiple_slave_address_slave) | RL78/G23の複数スレーブ・アドレス対応I2C (スレーブ)を行うプロジェクトです。 |
| SAU | [EP I2C](./rl78_g2x/rl78_g23/ep_sau_i2c_master) | RL78/G23のSAUによるI2C通信を使用するExample Projectです。 |
| SAU | [EP SPI](./rl78_g2x/rl78_g23/ep_sau_spi_master) | RL78/G23のSAUによるSPI通信を使用するExample Projectです。 |
| SAU | [EP UART](./rl78_g2x/rl78_g23/ep_sau_uart_master) | RL78/G23のSAUによるUART通信を使用するExample Projectです。 |
| Serial Interface | [UARTA](./rl78_g2x/rl78_g23/uarta) | RL78/G23のシリアル・インターフェースUARTAを使用するプロジェクトです。 |
| Serial Interface | [UART Reception in STOP Mode](./rl78_g2x/rl78_g23/uart_reception_stop_mode_using_uarta) | RL78/G23のUARTA を使用したSTOP モード時のUART 受信を行うプロジェクトです。 |
| Serial Interface | [EP UARTA](./rl78_g2x/rl78_g23/ep_uarta) | RL78/G23のシリアル・インターフェースUARTAを使用するExample Projectです。 |
| Serial Interface | [EP IICA Master](./rl78_g2x/rl78_g23/ep_iic_master_iica) | RL78/G23のシリアル・インターフェースIICA(マスタ送受信)を使用するExample Projectです。 |
| Power Management | [Operation State Switching](./rl78_g2x/rl78_g23/operation_state_switching) | RL78/G23のオペレーション・ステートの切り替えを行うプロジェクトです。 |
| Power Management | [Using VBAT Pin](./rl78_g2x/rl78_g23/using_vbat_pin) | RL78/G23のVBAT 端子の使い方を示すプロジェクトです。 |
| Port | [Output Current Control Ports](./rl78_g2x/rl78_g23/output_current_control_ports) | RL78/G23の出力電流制御ポートの使い方を示すプロジェクトです。 |
| Port | [40mA Port Output](./rl78_g2x/rl78_g23/40ma_port_output) | RL78/G23の40mAポート出力を示すプロジェクトです。 |
| Comparator | [Window Comparator](./rl78_g2x/rl78_g23/setting_window_comparator) | RL78/G23のウィンドウ・コンパレータの使い方を示すプロジェクトです。 |
| LVD | [Voltage Detector](./rl78_g2x/rl78_g23/voltage_detector) | RL78/G23の電圧検出回路を示すプロジェクトです。 |

### RL78/G24
| カテゴリ | フォルダ | 概要 |
|---|---|---|
| ADC | [ADC Advanced Mode Enaled](./rl78_g2x/rl78_g24/adc_advanced_mode_enabled) | RL78/G24のA/Dコンバータをアドバンスド・モードONで使用するプロジェクトです。 |
| ADC | [ADC Advanced Mode disaled](./rl78_g2x/rl78_g24/adc_advanced_mode_disabled) | RL78/G24のA/Dコンバータをアドバンスド・モードOFFで使用するプロジェクトです。 |
| Timer RD | [Timer RD2 Input Capture Function and Output Compare Function](./rl78_g2x/rl78_g24/timer_rd2_input_capture_function_output_compare_function) | RL78/G24のタイマRD2をタイマモード(インプットキャプチャ機能とアウトプットコンペア機能の併用)で使用するプロジェクトです。 |
| Timer RD | [Timer RD2 Timer Mode PWM Function](./rl78_g2x/rl78_g24/timer_rd2_timer_mode_pwm_function) | RL78/G24のタイマRD2をタイマモード(PWM機能)で使用するプロジェクトです。 |
| Timer RD | [Timer Window Output](./rl78_g2x/rl78_g24/timer_window_output_timer_rd2_timer_array_unit_comparator) | RL78/G24のタイマRD2とTAU、コンパレータ連動によるTIMER WINDOW出力をするプロジェクトです。 |
| Timer RG | [Timer RG2 Buffer Operation PWM Mode](./rl78_g2x/rl78_g24/timer_rg2_buffer_operation_pwm_mode) | RL78/G24のタイマRG2をPWMモード(バッファ動作)で使用するプロジェクトです。 |
| Timer RG | [Timer RG2 Phase Counting Mode](./rl78_g2x/rl78_g24/timer_rg2_phase_counting_mode) | RL78/G24のタイマRG2を位相計数モードで使用するプロジェクトです。 |

## RL78/L2x
- [RL78/L23](#rl78l23)

### RL78/L23
| カテゴリ | フォルダ | 概要 |
|---|---|---|
| LCD | [24H Clock](./rl78_l2x/rl78_l23/24_hour_clock_displayed_lcd) | RL78/L23のLCDコントローラ／ドライバを使用した24時間時計表示を行うプロジェクトです。 |
| LCD | [Display Clock](./rl78_l2x/rl78_l23/lcd_display_clock_demo) | RL78/L23のRTCとタッチボタンを使用したLCD時計表示を行うプロジェクトです。 |
| LCD | [Display Temperature](./rl78_l2x/rl78_l23/lcd_display_temperature_display_demo) | RL78/L23のタッチボタンを使用したLCD温度表示を行うプロジェクトです。 |
| Bank Swap | [Bank Swapping](./rl78_l2x/rl78_l23/bank_swapping_demo) | RL78/L23のバンクスワップによる時計表示／温度表示プログラム切り替えを行うプロジェクトです。 |
