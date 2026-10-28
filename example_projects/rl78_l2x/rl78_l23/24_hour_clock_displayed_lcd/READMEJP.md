# RL78/L23 LCD表示（時計編）

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/L23 に搭載されている LCDコントローラ／ドライバを用いた LCD パネルの制御方法およびサンプル・コードの動作について説明します。 サンプル・コードでは、LCDパネルに 24 時間形式の時計を表示します。時刻表示は 1 分ごとに更新されます。スイッチの押下により、時刻の調整が可能です。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.13.00 |
| e2 studio | V2025-04.1 (25.4.1) |
| CC-RL | V1.15.00 |
| IAR Embedded Workbench | V5.20.1 |
| IAR Compiler | V5.20.1.2826 |
| Smart Configurator | N/A |
| BSP | N/A |

## ハードウェア構成
- RL78/L23 Fast Prototyping Board (RTK7RLL230S00WS1BJ)
- VIM-878-DP-FC-S-LV

## 適用可能デバイス
- RL78/L23

## APNリンク
[RL78/L23 LCD表示（時計編）](https://www.renesas.com/ja/document/apn/rl78l23-24-hour-clock-displayed-lcd-rev100)
