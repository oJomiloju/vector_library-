import subprocess
import sys

sys.tracebacklimit = 0
COLORIZED = False
PROBLEM_NAME = "VECTOR ALGEBRA"
if COLORIZED:
    ENDCODE = '\033[0m'
    BOLD = '\033[1m'
    GREEN = '\033[92m'
    RED = '\033[91m'
else:
    ENDCODE = ''
    BOLD = ''
    GREEN = ''
    RED = ''

def test_output(cmd, correct_output):
    with subprocess.Popen(
            cmd, stdout=subprocess.PIPE) as p:
        output = p.stdout.read()
        returncode = p.poll()
        p.kill()
    return output, returncode


def test(name, tests, test_type="output", points=1):
    print('\n', BOLD, name, ENDCODE)
    print(" ", '-'*20)
    correct = 0
    for correct_output, cmd, testname in tests:
        print("  " + testname)
        print("  TEST:", cmd[1:])
        output, returncode = test_output(cmd, correct_output)
        
        try:
            if test_type == "output":
                assert output == correct_output
            else:
                assert returncode == correct_output
            correct += 1
            print(GREEN, "   PASS", '✓', ENDCODE)
        except Exception as err:
            print(RED, "   FAIL", '✗', ENDCODE)
            print(f'    {output} != {correct_output}')

    return correct, len(tests), points, name


currentResult = None  # holds last result object passed to run method


if __name__ == '__main__':
    print("\n", '*'*20)
    print(f" {BOLD}{PROBLEM_NAME}{ENDCODE}")
    print("", '*'*20)
    results = []



    # problem1 = [
    #     (b'[1.00 1.00 1.00] n=3\n[6.00 6.00 6.00] n=3\n',
    #         ["./mysolution", "3", "5", "2"], "Base Test"),
    #     (b'[1.00 1.00 1.00] n=3\n[6.00 6.00 6.00] n=3\n',
    #         ["./mysolution", "3", "6", "3"], "Base Test 2"),
    # ]
    
    # results.append(test("BASECASE", problem1, "output", 15))

    # problem2 = [
    #     (b'[1.00 2.00 3.00 4.00 5.00] n=5\n',
    #         ["./mysolution", "../data/hello.dat", "../data/result.dat"], "Read/Write Default"),
    #     (b'[1.00 1.00 1.00 0.00 0.00 0.00 1.00 1.00 1.00 0.00 0.00 1.00 1.00] n=13\n',
    #         ["./mysolution", "../data/a.dat", "../data/b.dat"], "Read/Write Args")
    # ]
    
    # results.append(test("BASECASE", problem2, "output", 30))

    # problem3 = [
    #     (b'[16.0 16.0 16.0 -1.0 0.0 -1.0 16.0 16.0 16.0 -1.0 0.0 16.0 16.0] n=13\n',
    #         ["./mysolution", "add", "../data/hello.dat", "../data/result.dat", "1"], "Add"),
    #     (b'[0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00] n=13\n',
    #         ["./mysolution", "mul", "../data/hello.dat", "../data/result.dat", "0"], "Mul"),
    # ]
    
    # results.append(test("BASECASE", problem3, "output", 25))

    problem4 = [
        (b'[0.35 0.35 0.35 0.00 0.00 0.00 0.35 0.35 0.35 0.00 0.00 0.35 0.35] n=13\n[0.35 0.35 0.35 -0.02 0.00 -0.02 0.35 0.35 0.35 -0.02 0.00 0.35 0.35] n=13\n',
            ["./mysolution", "unit", "../data/a.dat", "../data/b.dat", "1"], "Unit"),
        (b'2.83\n42.46\n',
            ["./mysolution", "mag", "../data/a.dat", "../data/b.dat", "0"], "Mag"),
    ]
    
    results.append(test("BASECASE", problem4, "output", 25))


    print('\n', BOLD, "SUMMARY", ENDCODE)
    print(" ", '-'*20)
    sumpts = 0
    sumpts_correct = 0 
    for t in results:
        correct, total, pts, name = t
        pts = pts + 0.000
        grade = correct/total*pts
        print(" ", name)
        print(f"    {grade}/{pts} pts")
        sumpts_correct = sumpts_correct + grade
        sumpts = sumpts + pts
    print("\n", '*'*20)
    print(f"{BOLD} FINAL GRADE: {sumpts_correct} / {sumpts} pts: {sumpts_correct/sumpts*100}%{ENDCODE}")
    print("", '*'*20)
    print(sumpts_correct)

