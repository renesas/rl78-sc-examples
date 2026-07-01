# RL78/G23 複数スレーブ・アドレス対応 I2C (スレーブ)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23 の全アドレス一致機能を利用し、複数スレーブ・アドレスに対応した I2Cバスのスレーブ機能を使用する方法を示します。 本アプリケーションノートでは、異なるスレーブ・アドレスで指定される 4 つのシリアル・メモリ (256 バイト×4) 機能を実現します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.05.00 |
| e2 studio | V2021-04 (21.4.0) |
| CC-RL | V1.10.00 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V1.0.1 |
| BSP | V1.00 |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LED (OSX10201-R)
- スイッチ (SW1)
- スイッチ (SW2)
- 1kΩ抵抗
- 10kΩ抵抗
- 0.47µFコンデンサ

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 複数スレーブ・アドレス対応 I2C (スレーブ)](https://www.renesas.com/ja/document/apn/rl78g23-i2c-supporting-multiple-slave-addresses-slave)
