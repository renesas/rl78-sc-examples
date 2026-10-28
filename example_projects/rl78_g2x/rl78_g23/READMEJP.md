# RL78/G23 Example Projects
English page is [here](./README.md).<br>

このディレクトリでは、RL78/G23のExample projectsを提供します。<br>
プロジェクトの使い方、用意するソフトウェア/ハードウェアについては、各APN、プロジェクトフォルダ内READMEをご参照ください。 
 <br>
 
-------------------------------------------------------------------------------------------------------------
Note: <br>
本サンプルコードをR7F104G製品へ移行する場合、対象デバイスを変更した後に、スマート・コンフィグレータで端子、クロックおよび使用する周辺機能の設定を確認し、必ずコードを再生成してください。<br>
コードを再生成することで、R7F104G製品で初期値から変更が必要なポート関連レジスタの設定コードが生成されます。

対象デバイスの変更方法およびスマート・コンフィグレータの操作方法については、以下の資料を参照してください。
-	[マイクロコントローラを変更する | V8.05.00](https://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.05.00/CS+.chm/po-ProjectOperation.chm/Output/po_function_pset_micon-nav-3.html)
- [e² studio Tips - プロジェクトに設定されたデバイスを変更する方法 | Renesas ルネサス](https://www.renesas.com/ja/video/e-studio-tips-how-change-device-project)
- [RL78 スマート・コンフィグレータユーザーガイド：CS+編](https://www.renesas.com/ja/document/man/rl78-smart-configurator-users-guide-cs?srsltid=AU7gw4Vf6CpRW-GQqD07IhZix8vxX6OqeIVmCRcsClgdMvfkM5oNOy8R)
- [RL78 スマート・コンフィグレータユーザーガイド: e² studio編](https://www.renesas.com/ja/document/man/rl78-smart-configurator-users-guide-e-studio?r=1622856)
-------------------------------------------------------------------------------------------------------------
 
## 対応表
| 内容 | アプリケーションノート番号 |
|--------|--------|
| 32-bit Interval Timer (8-bit Counter Mode) | r01an5564 |
| AD Converter (Scan Mode) | r01an5523 |
| AD Converter (Software Trigger Wait Mode) | r01an5631 | 
| Interval Timer | r01an5870 |
| Pulse Interval Measurement (Period) | r01an5908 |
| Pulse Interval Measurement (Width) | r01an5919 |
| PWM Output | r01an5874 |
| Realtime Clock | r01an5618 |
| UART Communication | r01an6645 |
| Serial Interface UARTA | r01an5598 |
| UART Reception in STOP Mode Using the UARTA Function | r01an6646 |
| Setting the Window Comparator | r01an5648 |
| I2C Supporting Multiple Slave Address (Master) | r01an5825 |
| I2C Supporting Multiple Master Address (Master) | r01an5670 |
| How to Use the Output Current Control Ports | r01an5625 |
| Handshake-based SPI Slave Transmission/Reception | r01an5890 |
| Handshake-based SPI Master Transmission/Reception | r01an5889 |
| 40mA Port Output | r01an5627 |
| Voltage Detector | r01an5604 |
| Using VBAT Pin | r01an5560 |
| LOCO Clock Frequency Correction | r01an5557 |
| MOCO Clock Frequency Correction | r01an5556 |
| HOCO Clock Frequency Correction | r01an5555 |
| CPU Clock Changing and Standby Settings | r01an5546 |
| Operation State Switching | r01an5537 |
| EP Quick Start | r01an8400* |
| EP ADC | r01an8401* |
| EP TAU | r01an8407* |
| EP I2C | r01an8404* |
| EP SPI | r01an8405* |
| EP UART | r01an8406* |
| EP Serial Interface UARTA | r01an8408* |
| EP Serial Interface IICA Master | r01an8402* |

*: これらのプロジェクトにはAPNが用意されていません。参照できるAPN番号を示していますので、参考にしてください。

## リンク
- RL78/G23: https://www.renesas.com/ja/products/rl78-g23
- RL78/G23 ユーザーズマニュアル: https://www.renesas.com/ja/document/man/rl78g23-users-manual-hardware
- FPB RL78/G23 64pin: https://www.renesas.com/ja/design-resources/boards-kits/fpb-rl78g23-64p
- FPB RL78/G23 128pin: https://www.renesas.com/ja/design-resources/boards-kits/fpb-rl78g23-128p
