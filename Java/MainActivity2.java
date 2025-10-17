package com.example.happybirthday;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.graphics.drawable.AnimationDrawable;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {

    ImageView solo,group,wide;
    @Override
    protected void onDestroy() {
        super.onDestroy();
        mediaPlayer.stop();
        mediaPlayer.release();
    }

    MediaPlayer mediaPlayer;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Intent intent = getIntent();
        String name = intent.getStringExtra(MainActivity.EXTRA_MESSAGE);

        // Capture the layout's TextView and set the string as its text
        TextView textView2 = findViewById(R.id.textView2);
        textView2.setText(name);
        solo= findViewById(R.id.solo);
        wide= findViewById(R.id.wide);
        group= findViewById(R.id.group);
        AnimationDrawable ad = (AnimationDrawable)solo.getDrawable();
        ad.start();
        AnimationDrawable ad1 = (AnimationDrawable)wide.getDrawable();
        ad1.start();
        AnimationDrawable ad2 = (AnimationDrawable)group.getDrawable();
        ad2.start();

        mediaPlayer = MediaPlayer.create(this , R.raw.hbd);
        mediaPlayer.setLooping(true);
        mediaPlayer.start();

    }

    public void Next(View view) {
        mediaPlayer.stop();
        startActivity(new Intent(this,MainActivity3.class));
    }
}
