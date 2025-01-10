
def read_file(name):
    content = list()
    with open(name, "r") as file:
        for line in file:
            numbers = list(map(int, line.rstrip("\n").split(" ")))
            content.append(numbers)
    return content

def is_report_safe(report):
    is_increasing = -1
    for i in range(1, len(report)):
        diff = report[i] - report[i-1]
        if (is_increasing == -1):
            is_increasing = diff > 0
        if ((0 == abs(diff) or abs(diff) > 3) or (is_increasing != (diff > 0))):
            return False
    return True 

def is_report_safe_with_dampening(report):
    if (is_report_safe(report)):
        return True
    for index in range(len(report)):
        new_report = report.copy()
        new_report.pop(index)
        if (is_report_safe(new_report)):
            return True
    return False

def main():
    content = read_file("input")

    safe_reports = 0
    for report in content:
        if (is_report_safe_with_dampening(report)):
            safe_reports += 1

    print(f"Safe reports: {safe_reports}")


if __name__ == "__main__":
    main()

