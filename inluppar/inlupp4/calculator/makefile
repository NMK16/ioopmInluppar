all:
	javac -d classes -sourcepath src/main/java src/main/java/org/ioopm/calculator/Calculator.java

tests:
	javac -cp junit-platform-console-standalone-1.8.1.jar -d classes -sourcepath src/main/java src/main/java/org/ioopm/calculator/tests/AdditionTest.java

runtests:
	java -jar junit-platform-console-standalone-1.8.1.jar -cp classes -c org.ioopm.calculator.tests.AdditionTest

run:
	java -cp classes org.ioopm.calculator.Calculator

clean:
	rm -rf classes