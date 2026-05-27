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

## RL78/G2x
- [RL78/G22](#rl78g22)
- [RL78/G23](#rl78g23)
- [RL78/G24](#rl78g24)

### RL78/G22
| カテゴリ | フォルダ | 概要 |
|---|---|---|
| ADC |  | RL78/G22のA/Dコンバータをソフトウェア・トリガ、スキャンモードで使用するプロジェクトです。|
| ADC |  | RL78/G22のA/Dコンバータをソフトウェア・トリガ、連続変換モードで使用するプロジェクトです。|
| TAU |  | RL78/G22のTAUによるインターバル・タイマ機能を使用するプロジェクトです。 |
| TAU |  | RL78/G22のTAUによるパルス間隔測定(周期)機能を使用するプロジェクトです。 |
| TAU |  | RL78/G22のTAUによるパルス間隔測定(幅)機能を使用するプロジェクトです。 |
| TAU |  | RL78/G22のTAUによるPWM出力機能を使用するプロジェクトです。 |
| Timer |  | RL78/G22の32ビット・インターバル・タイマを使用するプロジェクトです。 |
| SAU |  | RL78/G22のSAUによるUART通信を使用するプロジェクトです。 |
| Serial Interface |  | RL78/G22のシリアル・インターフェースIICA(スレーブ送受信)を使用するプロジェクトです。 |
| Serial Interface |  | RL78/G22のシリアル・インターフェースIICA(マスタ送受信)を使用するプロジェクトです。 |
| Serial Interface |  | RL78/G22のシリアル・インターフェースUARTAを使用するプロジェクトです。 |

### RL78/G23
| カテゴリ | フォルダ | 概要 |
|---|---|---|
| ADC | [ADC Scan Mode](./rl78_g2x/rl78_g23/adc_scan_mode) | RL78/G23のA/Dコンバータをスキャンモード(ソフトウェア・トリガ・ノーウェイト・モード、連続変換モード)で使用するプロジェクトです。 |
| ADC | [ADC Software Trigger Wait Mode](./rl78_g2x/rl78_g23/adc_software_trigger_wait_mode) | RL78/G23のA/Dコンバータをソフトウェア・トリガ・ウェイト・モード(セレクト・モード、ワンショット変換モード)で使用するプロジェクトです。|
| TAU | [Interval Timer](./rl78_g2x/rl78_g23/interval_timer) | RL78/G23 interval timer example |
| TAU | [Pulse Interval Measurement (Period)](./rl78_g2x/rl78_g23/pulse_interval_measurement_period) | RL78/G23 pulse interval measurement (period) example |
| TAU | [Pulse Interval Measurement (Width)](./rl78_g2x/rl78_g23/pulse_interval_measurement_width) | RL78/G23 pulse interval measurement (width) example |
| TAU | [PWM Output](./rl78_g2x/rl78_g23/pwm_output) | RL78/G23 PWM output example |
| Timer | [32-bit Interval Timer](./rl78_g2x/rl78_g23/32-bit_interval_timer) | RL78/G23 32-bit interval timer example |
| SAU | [UART](./rl78_g2x/rl78_g23/uart) | RL78/G23 UART example |
| Serial Interface | [UARTA](./rl78_g2x/rl78_g23/uarta) | RL78/G23 UARTA example |

### RL78/G24
| カテゴリ | フォルダ | 概要 |
|---|---|---|
| TAU | [Interval Timer](./rl78_g2x/rl78_g24/interval_timer) | RL78/G24 interval timer example |
| TAU | [Pulse Interval Measurement (Period)](./rl78_g2x/rl78_g24/pulse_interval_measurement_period) | RL78/G24 pulse interval measurement (period) example |
| TAU | [Pulse Interval Measurement (Width)](./rl78_g2x/rl78_g24/pulse_interval_measurement_width) | RL78/G24 pulse interval measurement (width) example |
| TAU | [PWM Output](./rl78_g2x/rl78_g24/pwm_output) | RL78/G24 PWM output example |
| Timer | [32-bit Interval Timer](./rl78_g2x/rl78_g24/32-bit_interval_timer) | RL78/G24 32-bit interval timer example |
