# motion-latch-buzzer
جهاز إنذار يعمل بالحركة مع صوت ونغمات عبر الأردوينو
# 🔔 مشروع حساس الحركة مع أضواء ونغمات | Motion-Activated Alert System

📌 **اللغة العربية:**

هذا المشروع باستخدام أردوينو يتيح تشغيل نظام إنذار عند الكشف عن الحركة، عبر حساس PIR. عند اكتشاف الحركة أو الضغط على الزر اليدوي، يصدر صوت مكوّن من ثلاث نغمات متدرجة، ثم نغمة متصلة، مع إضاءة LED داخلي بالاردوينو وخارجي.

## 🎯 المميزات:
- تشغيل يدوي بالنقر على زر
- تشغيل تلقائي عند اكتشاف الحركة
- صوت متدرج (هادئ ➜ متوسط ➜ قوي ➜ مستمر)
- إضاءة متزامنة مع الأصوات (LED داخلي وخارجي)
- إيقاف تلقائي بعد 3 ثواني من التشغيل

## 🧰 المكونات المطلوبة:
- لوحة Arduino Uno
- حساس حركة PIR
- زر ضغط (Push Button)
- LED داخلي (موجود في الأردوينو) + LED خارجي على breadboard
- مقاومة 220 أوم للـ LED الخارجي
- Passive Buzzer
- اسلاك توصيل

## 🔌 التوصيلات:
| المكوّن            | التوصيل                         |
|-------------------|----------------------------------|
| الزر اليدوي         | Pin 9 إلى GND                    |
| حساس الحركة (PIR)   | VCC إلى 5V، GND إلى GND، OUT إلى Pin 7 |
| LED الخارجي        | الطرف الموجب إلى Pin 12 عبر مقاومة، الطرف السالب إلى GND |
| البازر السلبي       | الموجب إلى Pin 6، السالب إلى GND |

## 💻 الكود:
الكود مكتوب بلغة C++ عبر بيئة Arduino IDE. جميع التبديلات والتحكمات موجودة داخل دالة `loop()` ودالة تشغيل النغمة `playIntroMelody()`.

---

📌 **English Version:**

This Arduino-based project triggers a motion-activated alert using a PIR sensor. When motion is detected or the manual button is pressed, the system plays three ascending tones followed by a continuous one. Both internal and external LEDs light up during the sounds.

## 🎯 Features:
- Manual toggle via push button
- Automatic trigger via PIR motion sensor
- Melody with 3 progressive tones + continuous buzzer
- LED feedback synced with tones
- Auto shutdown after 3 seconds

## 🧰 Components Used:
- Arduino Uno
- PIR Motion Sensor
- Push Button
- Internal LED + External Breadboard LED
- 220Ω resistor for external LED
- Passive Buzzer

## 🔌 Wiring:
| Component         | Connection                        |
|------------------|------------------------------------|
| Push Button       | Pin 9 to GND                      |
| PIR Sensor        | VCC to 5V, GND to GND, OUT to Pin 7 |
| External LED      | Anode to Pin 12 via resistor, Cathode to GND |
| Passive Buzzer    | Positive to Pin 6, Negative to GND |

## 💻 Code Overview:
Code is written in Arduino C++, handling logic in `loop()` and melody control in `playIntroMelody()`. It includes debounce logic for the button and uses `tone()` for buzzer frequency control.

---
بعض الملاحظات التي اتوقعها ان تكون مفيدة 
طريقة تشبيك الليد 
تشبيك الـ LED على breadboard
تأكدو إن:
| الطرف | التوصيل الصحيح | 
| الطرف الموجب (+) | إلى Pin 12 عبر مقاومة 220Ω | 
| الطرف السالب (–) | إلى GND مباشرة | 


📌 إذا ما استخدمتو مقاومة 220 أوم، ممكن الصوت يشتغل لكن الضوء ما يبين، أو العكس إذا المقاومة موصلة بالخطأ.
‼️ تأكدي من اتجاه الـ LED، لأن عكس الأرجل يمنع الإضاءة!
الطرف الطويل هو الموجب ➜ يذهب إلى المخرج الرقمي (Pin 12)
الافضل اختبار كل قطعة لوحدها و التاكد من طريقة التشبيك




🛠️ اختبرت المشروع باستخدام التنكركاد القطع الواقعية، ويمكن تعديل المدة أو نغمة البازر حسب الحاجة.
شكرا للقراءة واتمنى دعمي بمواقع التواصل الاجتماعي 
