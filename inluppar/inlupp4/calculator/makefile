all:
	javac -d classes -sourcepath src/main/java src/main/java/org/ioopm/calculator/Calculator.java

tests:
	javac -cp junit-platform-console-standalone-1.8.1.jar -d classes -sourcepath src/main/java src/main/java/org/ioopm/calculator/tests/*.java

runtests:
	java -jar junit-platform-console-standalone-1.8.1.jar -cp classes -p org.ioopm.calculator.tests


run:
	java -cp classes org.ioopm.calculator.Calculator

clean:
	rm -rf classes