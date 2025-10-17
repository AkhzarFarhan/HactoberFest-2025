package com.example.happybirthday;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    public static final String EXTRA_MESSAGE = "com.example.myfirstapp.MESSAGE";
    Button button;
    TextView textView;
    EditText editText;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button = findViewById(R.id.button);
        editText = findViewById(R.id.editText);
    }
    public void Next(View view) {
        String name = editText.getText().toString();
//        if (name == "Ankita") {
//            Intent intent = new Intent(this, MainActivity2.class);
//            intent.putExtra(EXTRA_MESSAGE, name);
//            startActivity(intent);
//        }
//            else if (name == "ankita") {
//                Toast.makeText(this, "Enter Ankita", Toast.LENGTH_SHORT).show();
//             }

        switch (name) {
            case "Ankita" :
                Intent intent1 = new Intent(this, MainActivity2.class);
                intent1.putExtra(EXTRA_MESSAGE, name);
                startActivity(intent1);
                break;

            case "ankita":
                Intent intent2 = new Intent(this, MainActivity2.class);
                intent2.putExtra(EXTRA_MESSAGE, name);
                startActivity(intent2);
                break;

            default:
                Toast.makeText(this, "Enter Ankita", Toast.LENGTH_SHORT).show();
                break;
        }

        }

    }