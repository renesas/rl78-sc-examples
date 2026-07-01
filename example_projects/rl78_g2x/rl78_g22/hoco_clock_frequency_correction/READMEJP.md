# RL78/G22 高速オンチップ・オシレータ・クロック 周波数補正

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G22 に搭載された HIOTRM レジスタを用いて高速オンチップ・オシレータの周波数補正方法を説明します。サブシステム・クロックまたは外部入力信号を用いて周波数誤差を検出します。HIOTRM を調整して発振周波数を 32MHz に近づけます。2 種類のキャリブレーション方法とサンプルコードを提供します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V9.11.04 |
| e2 studio | V2024-01 (21.4.0) |
| CC-RL | V1.13.00 |
| IAR Embedded Workbench | V5.10.3 |
| IAR Compiler | V5.10.3 |
| Smart Configurator | V1.10.0 |
| BSP | V1.62 |

## ハードウェア構成
- RL78/G22 Fast Prototyping Board (RTK7RLG220C00000BJ)
- スタート・スイッチ
- パラメータ・スイッチ
- 補正完了 LED
- 32.768 kHz 水晶発振子
- 抵抗 (10 kΩ)
- コンデンサ (0.47～1 µF)
- 外部入力信号 (512 Hz)

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 高速オンチップ・オシレータ・クロック 周波数補正](https://www.renesas.com/ja/document/apn/rl78g22-high-speed-chip-oscillator-hoco-clock-frequency-correction-rev100)
