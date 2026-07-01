# RL78/G23 電圧検出回路

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23 に搭載している 2 つの電圧検出回路 (LVD) を利用して 2 つの電圧を検出する方法を説明します。 電圧検出回路 0 (LVD0) はリセット･モードに設定し、電圧検出回路 1 (LVD1) は割り込みモードに設定します。 電圧検出回路 1 (LVD1) の検出電圧を下回ると、CPU／周辺ハードウエア・クロック周波数をサブシステム・クロックに切り替えて消費電力を低減させます。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.10.00 |
| e2 studio | V2023-10 (23.10.0) |
| CC-RL | V1.12.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.8.0 |
| BSP | V1.00 |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LED
- スイッチ
- XT1 32.768kHz

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 電圧検出回路](https://www.renesas.com/ja/document/apn/rl78g23-voltage-detector)
