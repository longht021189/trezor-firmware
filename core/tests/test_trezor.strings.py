# flake8: noqa: F403,F405
from common import *  # isort:skip

from trezor import strings


class TestStrings(unittest.TestCase):
    def test_format_amount(self):
        VECTORS = [
            (123456, 3, "123.456"),
            (4242, 7, "0.0004242"),
            (-123456, 3, "-123.456"),
            (-4242, 7, "-0.0004242"),
            (123, 5, "0.00123"),
            (100, 5, "0.001"),
            (123456789, 0, "123,456,789"),
            (100000000, 5, "1,000"),
            (100000001, 5, "1,000.00001"),
            (100001000, 5, "1,000.01"),
            (-100001000, 5, "-1,000.01"),
            (123_456_789_123_456_789_123_456_789, 18, "123,456,789.123456789123456789"),
        ]
        for v in VECTORS:
            self.assertEqual(strings.format_amount(v[0], v[1]), v[2])

    def test_format_plural_english(self):
        VECTORS = [
            ("We need {count} more {plural}", 1, "share", "We need 1 more share"),
            ("We need {count} more {plural}", 3, "share", "We need 3 more shares"),
            ("We need {count} more {plural}", 1, "candy", "We need 1 more candy"),
            ("We need {count} more {plural}", 7, "candy", "We need 7 more candies"),
            ("We need {count} more {plural}", 1, "key", "We need 1 more key"),
            ("We need {count} more {plural}", 5, "key", "We need 5 more keys"),
            ("We need {count} more {plural}", 1, "hash", "We need 1 more hash"),
            ("We need {count} more {plural}", 2, "hash", "We need 2 more hashes"),
            ("We need {count} more {plural}", 1, "fuzz", "We need 1 more fuzz"),
            ("We need {count} more {plural}", 2, "fuzz", "We need 2 more fuzzes"),
        ]
        for v in VECTORS:
            self.assertEqual(strings.format_plural_english(v[0], v[1], v[2]), v[3])

        with self.assertRaises(ValueError):
            strings.format_plural_english("Hello", 1, "share")

    def test_format_plural(self):
        VECTORS = [
            (
                "You are about to sign {count} {plural}",
                0,
                "action|actions",
                "You are about to sign 0 actions",
            ),
            (
                "You are about to sign {count} {plural}",
                1,
                "action|actions",
                "You are about to sign 1 action",
            ),
            (
                "You are about to sign {count} {plural}",
                3,
                "action|actions",
                "You are about to sign 3 actions",
            ),
            (
                "You are about to sign {count} {plural}",
                15,
                "action|actions",
                "You are about to sign 15 actions",
            ),
            (
                "Chystáte se podepsat {count} {plural}",
                0,
                "akci|akce|akcí",
                "Chystáte se podepsat 0 akcí",
            ),
            (
                "Chystáte se podepsat {count} {plural}",
                1,
                "akci|akce|akcí",
                "Chystáte se podepsat 1 akci",
            ),
            (
                "Chystáte se podepsat {count} {plural}",
                3,
                "akci|akce|akcí",
                "Chystáte se podepsat 3 akce",
            ),
            (
                "Chystáte se podepsat {count} {plural}",
                15,
                "akci|akce|akcí",
                "Chystáte se podepsat 15 akcí",
            ),
        ]
        for v in VECTORS:
            self.assertEqual(strings.format_plural(v[0], v[1], v[2]), v[3])

        with self.assertRaises(ValueError):
            strings.format_plural("Hello", 1, "share")

    def test_format_duration_ms(self):
        unit_plurals = {
            "millisecond": "millisecond|milliseconds",
            "second": "second|seconds",
            "minute": "minute|minutes",
            "hour": "hour|hours",
        }

        VECTORS = [
            (0, "0 milliseconds"),
            (1, "1 millisecond"),
            (999, "999 milliseconds"),
            (1000, "1 second"),
            (2345, "2 seconds"),
            (59999, "59 seconds"),
            (60 * 1000, "1 minute"),
            (119 * 1000, "1 minute"),
            (120 * 1000, "2 minutes"),
            (59 * 60 * 1000, "59 minutes"),
            (60 * 60 * 1000, "1 hour"),
            (119 * 60 * 1000, "1 hour"),
            (3 * 60 * 60 * 1000, "3 hours"),
            (48 * 60 * 60 * 1000, "48 hours"),
        ]

        for v in VECTORS:
            self.assertEqual(strings.format_duration_ms(v[0], unit_plurals), v[1])

    def test_format_timestamp(self):
        VECTORS = [
            (0, "1970-01-01 00:00:00"),
            (123456, "1970-01-02 10:17:36"),
            (246912, "1970-01-03 20:35:12"),
            (370368, "1970-01-05 06:52:48"),
            (493824, "1970-01-06 17:10:24"),
            (10000, "1970-01-01 02:46:40"),
            (12355678, "1970-05-24 00:07:58"),
            (24701356, "1970-10-13 21:29:16"),
            (37047034, "1971-03-05 18:50:34"),
            (49392712, "1971-07-26 16:11:52"),
            (1610057224, "2021-01-07 22:07:04"),
            (1610806549, "2021-01-16 14:15:49"),
            (1611555874, "2021-01-25 06:24:34"),
            (1612305199, "2021-02-02 22:33:19"),
            (1613054524, "2021-02-11 14:42:04"),
            (1613803849, "2021-02-20 06:50:49"),
            (1614553174, "2021-02-28 22:59:34"),
            (1615302499, "2021-03-09 15:08:19"),
            (1616051824, "2021-03-18 07:17:04"),
            (1616801149, "2021-03-26 23:25:49"),
            (1617550474, "2021-04-04 15:34:34"),
            (1618299799, "2021-04-13 07:43:19"),
            (1619049124, "2021-04-21 23:52:04"),
            (1619798449, "2021-04-30 16:00:49"),
            (1620547774, "2021-05-09 08:09:34"),
            (1621297099, "2021-05-18 00:18:19"),
            (1622046424, "2021-05-26 16:27:04"),
            (1622795749, "2021-06-04 08:35:49"),
            (1623545074, "2021-06-13 00:44:34"),
            (1624294399, "2021-06-21 16:53:19"),
            (1625043724, "2021-06-30 09:02:04"),
            (1625793049, "2021-07-09 01:10:49"),
            (1626542374, "2021-07-17 17:19:34"),
            (1627291699, "2021-07-26 09:28:19"),
            (1628041024, "2021-08-04 01:37:04"),
            (1628790349, "2021-08-12 17:45:49"),
            (1629539674, "2021-08-21 09:54:34"),
            (1630288999, "2021-08-30 02:03:19"),
            (1631038324, "2021-09-07 18:12:04"),
            (1631787649, "2021-09-16 10:20:49"),
            (1632536974, "2021-09-25 02:29:34"),
            (1633286299, "2021-10-03 18:38:19"),
            (1634035624, "2021-10-12 10:47:04"),
            (1634784949, "2021-10-21 02:55:49"),
            (1635534274, "2021-10-29 19:04:34"),
            (1636283599, "2021-11-07 11:13:19"),
            (1637032924, "2021-11-16 03:22:04"),
            (1637782249, "2021-11-24 19:30:49"),
            (1638531574, "2021-12-03 11:39:34"),
            (1639280899, "2021-12-12 03:48:19"),
            (1640030224, "2021-12-20 19:57:04"),
            (1640779549, "2021-12-29 12:05:49"),
            (1641528874, "2022-01-07 04:14:34"),
            (976838400, "2000-12-15 00:00:00"),
            (976838399, "2000-12-14 23:59:59"),
            (976838401, "2000-12-15 00:00:01"),
            (1119398400, "2005-06-22 00:00:00"),
            (1119398399, "2005-06-21 23:59:59"),
            (1119398401, "2005-06-22 00:00:01"),
            (1261958400, "2009-12-28 00:00:00"),
            (1261958399, "2009-12-27 23:59:59"),
            (1261958401, "2009-12-28 00:00:01"),
            (1404518400, "2014-07-05 00:00:00"),
            (1404518399, "2014-07-04 23:59:59"),
            (1404518401, "2014-07-05 00:00:01"),
            (1547078400, "2019-01-10 00:00:00"),
            (1547078399, "2019-01-09 23:59:59"),
            (1547078401, "2019-01-10 00:00:01"),
            (1689638400, "2023-07-18 00:00:00"),
            (1689638399, "2023-07-17 23:59:59"),
            (1689638401, "2023-07-18 00:00:01"),
            (1832198400, "2028-01-23 00:00:00"),
            (1832198399, "2028-01-22 23:59:59"),
            (1832198401, "2028-01-23 00:00:01"),
            (1891987200, "2029-12-15 00:00:00"),
            (1891987199, "2029-12-14 23:59:59"),
            (1891987201, "2029-12-15 00:00:01"),
            (2747347200, "2057-01-22 00:00:00"),
            (2747347199, "2057-01-21 23:59:59"),
            (2747347201, "2057-01-22 00:00:01"),
            (3602707200, "2084-03-01 00:00:00"),
            (3602707199, "2084-02-29 23:59:59"),
            (3602707201, "2084-03-01 00:00:01"),
            (7982409599, "2222-12-14 23:59:59"),
            (7982409600, "2222-12-15 00:00:00"),
            (7982409601, "2222-12-15 00:00:01"),
        ]

        for v in VECTORS:
            self.assertEqual(strings.format_timestamp(v[0]), v[1])

        strings.format_timestamp(1616057224)


if __name__ == "__main__":
    unittest.main()
