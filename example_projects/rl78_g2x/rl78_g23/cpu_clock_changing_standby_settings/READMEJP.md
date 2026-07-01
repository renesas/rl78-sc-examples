# RL78/G23 CPU クロックの切り替えとスタンバイ設定

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23 のCPU クロックの切り替えとスタンバイ設定 (動作モードの切り替え) を説明します。本アプリケーションでは、スイッチ入力により、CPU クロックと動作モードの切り替えを行います。5 つの LED 点灯を制御し、CPU クロックの状態と動作モードを表します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | E8.09.00 |
| e2 studio | V2023-04 (23.4.0) |
| CC-RL | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.6.0 |
| BSP | V1.60 |

## ハードウェア構成
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LED
- スイッチ

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 CPU クロックの切り替えとスタンバイ設定](https://www.renesas.com/ja/document/apn/rl78g23-cpu-clock-changing-and-standby-settings)
