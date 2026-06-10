# RL78/G24 タイマRG2 PWMモード（バッファ動作）

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G24のタイマRG2のPWMモード（バッファ動作）を用いてPWM波形を出力する方法を説明します。周期100μsのPWM信号を出力し、デューティ比を周期ごとに連続的に変化させます。デューティの変更はコンペア一致割り込みにより行われます。ハードウェア動作やデューティ変更処理、ソフトウェア設定について詳しく解説しています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.10.00 |
| e2 studio | 2023-07 (23.7.0) |
| CC-RL | V1.12.01 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V.1.7.0 |
| BSP | V.1.60 |

## ハードウェア構成
- RL78/G24 Fast Prototyping Board (RTK7RLG240C00000BJ)

## 適用可能デバイス
- RL78/G24

## APNリンク
[RL78/G24 タイマRG2 PWMモード（バッファ動作）](https://www.renesas.com/ja/document/apn/rl78g24-timer-rg2-buffer-operation-pwm-mode-rev100)
