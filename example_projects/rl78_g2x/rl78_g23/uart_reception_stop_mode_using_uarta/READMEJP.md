# RL78/G23 UARTAを使用した STOPモード時のUART受信

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23 のシリアル・インタフェースUARTA とキー割り込み機能を使用して STOP モード時にUART 受信する方法を説明します。RL78/G23は対向機器からデータが送られてくると、キー割り込み機能によってスタート・ビットの立ち下がりを検出し、STOPモードを解除します。STOPモードが解除されると、UARTAが動作を開始し、スタート・ビットに続くデータをUART受信します。なお、STOPモード解除時間によるUARTA動作の開始遅延は、ボー・レート許容誤差に含まれます。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.09.00 |
| e2 studio | V2023-01 (23.1.0) |
| CC-RL | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V.1.4.0 |
| BSP | V.1.30 |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 UARTAを使用した STOPモード時のUART受信](https://www.renesas.com/ja/document/apn/rl78g23-uart-reception-stop-mode-using-uarta-function-rev110)
